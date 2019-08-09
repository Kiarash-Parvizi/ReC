//---------------------------------------------------------------------------
// Process:
void Read_Change_Write();
int sectionNum; strList* rootSections;

void Process(strList* fileList) {
	rootSections = List_Create();
	//---------------------------
	printf("Processing...\n"); char* outName; outName = (char*)malloc(1); char logMessage[100];
	uint listSize = fileList->size;
	for (int i = 0; i < listSize; i++)
	{
		//Selecting the files
		f = fopen(fileList->e[i], "r");
		outName[0] = '\0'; append(&outName, ptext_REC_fslash); append(&outName, fileList->e[i]);
		//printf("outName: %s\n", outName);
		outFile = fopen(outName, "w+");

		//Main Process
		Read_Change_Write();

		//LOG
		fprintf(logFile, "%s : { sectionCount = %d; }\n", outName, sectionNum);
		fclose(f); fclose(outFile);
	}
}

//---------------------------------------------------------------------------



void Read_Change_Write() {
	char temp[64]; int temp_i;
	//
	char buffer [128];		char* secPtr; uint curlyPos;
	char buffer2[128];
	char sectionName[64];	char rootSecName[64]; sectionNum = 0;
	char secDepth = 0;		char skipNextRound = 0;
	char writeSectionRefs = 0;
	int sideCurlyCount = 0;
	//
	int location; char* localPtr;
	//
	while (fgets(buffer, 128, f) != NULL)
	{
		//Skip
		if (skipNextRound) { skipNextRound = 0; continue; }

		//Rec ref keywords {this, root, parent, '::'}
		{
			localPtr = buffer;
			//keyword = '::'------------------------
			while (location = findDoubleColon(localPtr))
			{
				replace(localPtr, &localPtr[location], 2, "___", 3);
				localPtr = localPtr + location + 2;
				//fputc('V', outFile);
			}
			if (sideCurlyCount > 0)
			{
				//keyword = this------------------------
				localPtr = buffer;
				while ((location = findInStr(localPtr, "this.")) != -1)
				{
					char* prefix = sectionList[activeSection].prefix;
					replace(localPtr, &localPtr[location], 5, prefix, strlen(prefix));
					//fputc('V', outFile);
					localPtr = localPtr + findCInStr(localPtr, ';');
					if (localPtr == buffer) break;
				}
				//keyword = root------------------------
				localPtr = buffer;
				while ((location = findInStr(localPtr, "root.")) != -1)
				{
					char* prefix = sectionList[activeSection].root;
					replace(localPtr, &localPtr[location], 5, prefix, strlen(prefix));
					//fputc('V', outFile);
					localPtr = localPtr + findCInStr(localPtr, ';');
					if (localPtr == buffer) break;
				}
				//keyword = parent------------------------
				localPtr = buffer;
				while ((location = findInStr(localPtr, "parent.")) != -1)
				{
					char* prefix = sectionList[activeSection].parent;
					replace(localPtr, &localPtr[location], 7, prefix, strlen(prefix));
					//fputc('V', outFile);
					localPtr = localPtr + findCInStr(localPtr, ';');
					if (localPtr == buffer) break;
				}
				//------------------------
			}
		}

		//Put section refs
		if (writeSectionRefs) {
			char b[64]; sprintf(b, "#include\"%s_refs.h\" // %s\n", sectionName, sectionName);
			fputs(b, outFile);
			writeSectionRefs = 0;
		}

		//Check For section keyword
		if ((secPtr = strstr(buffer, "section")) && !strstr(buffer, "struct") && !findCInStr(buffer, '"')
			&& !findCInStr(buffer, '/') && !findCInStr(buffer, '*'))
		{
			secPtr += 8; if (*(secPtr - 1) != ' ') goto OUT;
			getSectionName(sectionName, secPtr);
			/*printf("-------------SECTION KEYWORD FOUND\t|%s\n", sectionName);*/ sectionNum++;
			Section_ADD(sectionName);
			secDepth++;
			if (curlyPos = findCInStr(buffer, '{')) {
				if (secDepth == 1) {
					//RootSection List ADD
					if (!List_Find(rootSections, sectionName)) {
						char* rootName = (char*)malloc(64);
						strcpy(rootName, sectionName);
						List_ADD(rootSections, rootName);
						// Create refs file:
						sprintf(temp, "ReC/%s_refs.h\0", rootName);
							refsFile = fopen(temp, "w");
					}
					else {
						// Open refs file:
						sprintf(temp, "ReC/%s_refs.h\0", sectionName);
						refsFile = fopen(temp, "a");
					}
					//
					strcpy(rootSecName, sectionName);
					writeSectionRefs = 1;
				}
				continue;
			} else {
				skipNextRound = 1; if (secDepth == 1) writeSectionRefs = 1; continue;
			}
		}

		//Get and Modify elements based on section (&& save refs to <rootSection>_refs.h)
		if (secDepth > 0 && sideCurlyCount == 0)
		{
			if ((temp_i = findFunctionStart(buffer)) != -1) {
				char* elName = getElementName(buffer+temp_i);
				sprintf(temp, "%s%s\0", sectionList[activeSection].prefix, elName);
				replace(buffer, buffer+temp_i, strlen(elName), temp, strlen(temp));

				//add to refs.h
				strcpy(buffer2, buffer);
				if (!replaceC(buffer2, '{', ';')) { sprintf(buffer2, "%s;", buffer2); }
				fputs(buffer2, refsFile);
			}
		}

		//Curly Counter
		{
			sideCurlyCount += getCCountInStr(buffer, '{');
			sideCurlyCount -= getCCountInStr(buffer, '}');
			if (sideCurlyCount < 0) {
				secDepth += (sideCurlyCount);
				while (sideCurlyCount < 0)
				{
					Section_Close(); sideCurlyCount++;
				}
				continue;
			}
		}
		OUT:
		fputs(buffer, outFile);
	}
}

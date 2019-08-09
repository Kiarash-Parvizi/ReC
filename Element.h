//SECTION----------------------------------------------------

void getSectionName(char* secName, char* ptr) {
	uint secLen = 0;
	while (*ptr == ' ')
	{
		ptr++;
	}
	for (; ptr[secLen] != '{' && ptr[secLen] != ' ' && ptr[secLen] != '\0' && ptr[secLen] != '\n'; secLen++) {

	}
	for (uint i = 0; i < secLen; i++) {
		secName[i] = ptr[i];
	}	secName[secLen] = '\0';
}

//-----------------------------------------------------------

//Element----------------------------------------------------

char* getElementName(char* ptr) {
	uint elLen = 0;
	while (*ptr == ' ')
	{
		ptr++;
	}
	for (; ptr[elLen] != '(' && ptr[elLen] != '{' && ptr[elLen] != ' ' && ptr[elLen] != '\0'; elLen++) {

	}
	char* funcName = (char*)malloc(elLen + 1);
	for (uint i = 0; i < elLen; i++) {
		funcName[i] = ptr[i];
	}	funcName[elLen] = '\0';
	return funcName;
}

int findFunctionStart(char* ptr) {
	uint idenIndex = findCInStr(ptr, '(');
	if (idenIndex == 0) {
		return -1;
	}
	char onSpace = 1; idenIndex--;
	for (; 1; idenIndex--) {
		if (onSpace && ptr[idenIndex] != ' ') onSpace = 0;
		if (!onSpace && ptr[idenIndex] == ' ') {
			break;
		}
	}
	return idenIndex + 1;
}

//-----------------------------------------------------------

//Function Main----------------------------------------------

//char canFindMainFunc(char* ptr) {
//	char* mainLoc = NULL;
//	for (int i = 0; ptr[i] != '\0'; i++) {
//		if (ptr[i] == 'm') {
//			if (ptr[i+1] != 'a') continue;
//			if (ptr[i+2] != 'i') continue;
//			if (ptr[i+3] != 'n') continue;
//			mainLoc = ptr + i;
//			break;
//		}
//	}
//	if (mainLoc != NULL)
//	{
//		for (int i = 0; mainLoc[i] != '\0'; i++) {
//			if (mainLoc[i] == '(') return 1;
//		}
//	}
//	return 0;
//}

//-----------------------------------------------------------
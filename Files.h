
void Start_OpenDataFile() {
	logFile = fopen("ReC/log.txt", "w+");
	if (logFile != NULL) {
		return;
	}

	system("mkdir ReC");
	printf("ReC directory was created\n");
	logFile = fopen("ReC/log.txt", "w+");	
}

char isFile(char* name) {
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] == '.') { i++;
			if (name[i] == 'c' || name[i] == 'C' ||
				name[i] == 'h' || name[i] == 'H')
			{
				return 1;
			}
		}
	}
	return 0;
}

strList* getFilesInDir(char* dir) {
	strList* list = List_Create();
	FILE* fp; char buffer[128];

	fp = popen("ls", "r");
	if (fp != NULL) {
		while (fgets(buffer, 128, fp) != NULL) {
			replaceC(buffer, '\n', '\0');
			if (isFile(buffer)) {
				List_ADD(list, buffer);
				//printf(">>");
			}
			//printf("%s\n", buffer);
			strClear(buffer, 120);
		}
	}
	if (list->size == 0) {
		printf("\n--------------------\nERR:\nNo valid '.c' or '.h' file was found--------------------\n");
	} printf("\n\n");
	
	//List_Print(list);
	return list;
}

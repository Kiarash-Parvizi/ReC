#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#ifdef _WIN32
#else
#endif

#include"Platform.h"
#include"Var.h"
#include"Str.h"
#include"List.h"
#include"Section.h"
#include"Element.h"
#include"Process.h"

#include"Files.h"

int main(int argc, char** argv) {
	//
	//
	Start_GetPlatform();
	Start_Section();
	Start_Vars();
	Start_CheckForLS();
	Start_OpenDataFile();

	if (argc == 1) {
		strList* fileList = getFilesInDir(".");
		Process(fileList);
	}
	else {
		//Help:
		if (argv[1][0] == 'h' || argv[1][0] == 'H') {
			printf("%s", help_message);
			return 0;
		}
		for (int i = 1; i < argc; i++) {
			//Flag
			if (argv[i][0] == '+') {
				
			}
		}
	}

	printf("New files are saved at ./ReC\n");
	return 0;
}

//---------------------------------------------------



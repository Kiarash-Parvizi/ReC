//---------------------------------------------------------------------------
typedef struct Section {
	char* name;

	char* root; char* parent;
	char* prefix;
} Section;

//---------------------------------------------------------------------------
Section* sectionList; uint sectionCount = 0; int activeSection = -1; uint sectionListSize = 0;

//---------------------------------------------------------------------------

void Start_Section() {
	sectionList = (Section*)malloc(1);
}

//---------------------------------------------------------------------------
void Section_ADD(char* name) {
	sectionCount++; activeSection++;
	// Reallocate
	if (sectionCount > sectionListSize) {
		sectionList = (Section*)realloc(sectionList, sectionCount * (sizeof(Section)));
		sectionListSize++;
		// Malloc
		sectionList[activeSection].prefix = (char*)malloc(64);
		sectionList[activeSection].parent = (char*)malloc(64);
		sectionList[activeSection].root = (char*)malloc(64);
		sectionList[activeSection].name	= (char*)malloc(64);
	}
	// SET properties:
		// set name
		strcpy(sectionList[activeSection].name, name);
		// set prefix, parent, root
		if (activeSection == 0) {
			sprintf(sectionList[activeSection].prefix, "%s___", name);
			sprintf(sectionList[activeSection].parent, "%s___", name);
			sprintf(sectionList[activeSection].root, "%s___", name);
		}
		else {
			sprintf(sectionList[activeSection].prefix, "%s%s___", sectionList[activeSection-1].prefix, name);
			strcpy(sectionList[activeSection].parent,	sectionList[activeSection-1].prefix);
			strcpy(sectionList[activeSection].root,		sectionList[0].prefix);
		}
	//-----------------------------------------
}

void Section_Close() {
	activeSection--; sectionCount--;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

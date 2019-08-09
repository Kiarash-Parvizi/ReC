
typedef struct strList
{
	char** e;
	uint size;
} strList;

strList* List_Create() {
	strList* list = (strList*)malloc(sizeof(strList)); list->e = (char**)malloc(1); list->size = 0;
	return list;
}

void List_ADD(strList* list, char* el) {
	uint index = list->size; list->size++;
	list->e = (char**)realloc(list->e, list->size*sizeof(strList));
	char* memLoc = (char*)malloc(strlen(el));
	strcpy(memLoc, el);
	list->e[index] = memLoc;
}

char List_Find(strList* list, char* el) {
	for (int i = 0; i < list->size; i++) {
		if (strcmp(list->e[i], el) == 0)
			return 1;
	}
	return 0;
}

void List_Print(strList* list) {
	printf("\n");
	for (int i = 0; i < list->size; i++) {
		printf("%s\n", list->e[i]);
	}
	printf("\n");
}

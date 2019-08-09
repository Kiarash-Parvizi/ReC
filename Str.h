
void append(char** str, char* val) {
	int i = strlen(*str);
	*str = (char*)realloc(*str, i+strlen(val)+1);
	for (int a = 0; val[a] != '\0'; a++) {
		(*str)[i] = val[a];
		i++;
	}
	(*str)[i] = '\0';
}

char replaceC(char* str, char c, char newC) {
	char replaced = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
		{
			str[i] = newC; replaced = 1;
		}
	}
	return replaced;
}

// reaplace part of a string
void replace(char* str, char* start, uint len, char* newStr, uint newLen) {
	/*uint strLen = strlen(str);*/ int x; /*uint newStrLen;*/ uint for_to;
	uint start_strLen = strlen(start);
	int i = 0;
	if (newLen >= len)
	{
		for (; i < len; i++) {
			start[i] = newStr[i];
		}
		//realloc:
		x = newLen-len; //newStrLen = strLen + x + 1;
		//str = (char*) realloc(str, newStrLen);
		//1: shift all by (newLen-len) to the right
		for (int a = start_strLen; a >= i; a--) {
			start[a + x] = start[a];
		}
		x += i;
		//2: fill the gap
		for (; i < x; i++) {
			start[i] = newStr[i];
		}
	}
	else
	{
		for (; i < newLen; i++) {
			start[i] = newStr[i];
		}
		x = len-newLen; //newStrLen = strLen - x;
		//OP2: remove remaining
		for_to = start_strLen - x;
		for (; i <= for_to; i++) {
			start[i] = start[i + x];
		}
		//realloc:
		//str = (char*)realloc(str, newStrLen);
	}
}

uint findCInStr(char* str, char c) {
	for (uint i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) return i;
	}
	return 0;
}

uint findCInStr_reverseSearch(char* str, char c) {
	for (uint i = 0; str[i] != '\0'; i--) {
		if (str[i] == c) return i;
	}
	return 0;
}

uint findCInStrRange(char* str, uint searchLen, char c) {
	for (uint i = 0; i < searchLen; i++) {
		if (str[i] == c) return i;
	}
	return 0;
}

uint findDoubleColon(char* str) {
	for (uint i = 0; str[i] != '\0'; i++) {
		if (str[i] == ':' && str[i+1] == ':') return i;
	}
	return 0;
}

uint findTripleULine(char* str) {
	for (uint i = 0; str[i] != '\0'; i++) {
		if (str[i] == '_' && str[i + 1] == '_' && str[i + 2] == '_') return i;
	}
	return 0;
}

int findInStr(char* str, const char* sub) {
	int b, j; char c1 = sub[0];
	for (int i = 0; str[i] != '\0';) {
		if (str[i] == c1) {
			b = 1; j = i + 1;
			for (; sub[b] != '\0'; b++) {
				if (str[j] != sub[b]) {
					goto LE;
				}
				j++;
			}
			return i;
		}
	LE:
		i++;
	}
	return -1;
}

uint getCCountInStr(char* str, char c) {
	uint ccount = 0;
	for (uint i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) ccount++;
	}
	return ccount;
}

//-----------------------------------------------------------

void strClear(char* str, char count) {
	for (; count > -1; count--) {
		str[count] = '\0';
	}
}

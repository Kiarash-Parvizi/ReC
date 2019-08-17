#define uint unsigned int
//---------------------------------------------------------------------------
// Vars:
char* help_message = "ReC-HELP:\n>>>Usage:\n>>By running 'rec' command, ReC scans your current dir location for files with .c and .h extenstion\n>>then it converts your ReC code to good old C which you can compile using gcc or any other c compiler\n>>See 'https://github.com/Kiarash-Parvizi/ReC' for more details.";
char* err_invalidFormat1 = "\nERR:\nYour input format is incorrect\nTry using ReC -c=\"compilerPath\" \"filePath\"";
char* err_invalidSection = "\nERR:\nIncorrect section definition\n_correct pattern: section secName {\n";
char* compilerPath = "gcc"; char* applicationPath; char* outName;

char mainFuncFound = 0;

FILE* logFile; FILE* f; FILE* outFile; FILE* refsFile;

char* ptext_REC_fslash = "ReC/";

//---------------------------------------------------------------------------
// Funcs :
void Start_Vars() {
	compilerPath = "gcc";
}


//---------------------------------------------------------------------------
/* new keywords :
section, this, parent, root, inSec
*/
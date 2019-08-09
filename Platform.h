//---------------------------------------------------------------------------

char platform; // {w, u}

// Checks if it can find the 'ls' command
void Start_CheckForLS() {
	int err = system("ls");
	if (platform == 'w')  system("cls");
	if (platform == 'u')  system("clear");
	if (err == 1) {
		printf("\n------------------------!UNIX\n'ls' command not fount\nPlease place the ls.exe file in the same location as the main executable (ReC.exe) if you are using windows\n------------------------");
	}
	printf("---------------------------------------------------------------\n>>Designed by Kiarash Parvizi\n>>For more info run 'ReC help' command\n->Contact me at: cdev.developer@gmail.com\n---------------------------------------------------------------\n");
}

void Start_GetPlatform() {
#ifdef _WIN32
	platform = 'w';
#else
	platform = 'u'
#endif
}

//---------------------------------------------------------------------------
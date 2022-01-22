/***************************************************************\
*	finder: Program to recursively count images.		*
*	(c) 2022, Nate Morrison					*
\***************************************************************/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char cmd[56 + sizeof(argv[1])];

	if (argc < 2) {
		fprintf(stderr, "%s: No argument provided.\n", argv[0]);
		return 1;
	}

	if (argc > 2) {
		fprintf(stderr, "%s: Too many arguments.\n", argv[0]);
		return E2BIG;
	}
	
	strcpy(cmd, "ls -R ");
	strcat(cmd, argv[1]);
	strcat(cmd, " | egrep -Hi \".png|.jpg|.jpeg|.gif|.jfif|.webp\" | wc -l");
	// This was written under the assumption FreeBSD egrep was being used.

	system(cmd);
	return 0;
}

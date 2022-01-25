/***************************************************************\
*	finder: Program to recursively count images.		*
*	(c) 2022, Nate Morrison					*
\***************************************************************/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char cmd[435 + sizeof(argv[1])];

	if (argc < 2) {
		fprintf(stderr, "%s: No argument provided.\n", argv[0]);
		return 1;
	}

	if (argc > 3) {
		fprintf(stderr, "%s: Too many arguments.\n", argv[0]);
		return E2BIG;
	}
	
	if (argc == 2 && argv[2] == NULL) {
		strcpy(cmd, "ls -R ");
		strcat(cmd, argv[1]);
		strcat(cmd, " | egrep -Hi \".png|.jpg|.jpeg|.gif|.jfif|.webp\" | wc -l");
	}

	if (strcmp(argv[1], "--full") == 0 || strcmp(argv[1], "-f") == 0) {
		strcpy(cmd, "ls -R ");
		strcat(cmd, argv[2]);
		strcat(cmd, " | egrep -Hi \".jp2|.j2k|.jpf|.jpm|.jpg2|.j2c|.jpc|.jpx|.mj2|.jpg|.jpeg|.jpe|.jif|.jfif|.jfi|.png|.apng|.heif|.heifs|.heic|.heics|.avci|.avcs|.avif|.avifs|.3fr|.ari|.arw|.bay|.braw|.crw|.cr2|.cr3|.cap|.data|.dcs|.dcr|.dng|.drf|.eip|.erf|.fff|.gpr|.iiq|.k25|.kdc|.mdc|.mef|.mos|.mrw|.nef|.nrw|.obm|.orf|.pef|.ptx|.pxn|.r3d|.raf|.raw|.rwl|.rw2|.rwz|.sr2|.srf|.srw|.tif|.x3f|.tiff|.tif|.pbm|.pgm|.ppm|.pnm|.tga|.icb|.vda\" | wc -l"); // exotic formats
	}

	system(cmd);
	return 0;
}

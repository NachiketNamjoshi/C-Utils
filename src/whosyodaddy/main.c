#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#define MAX_LENGTH 255

int main(int argc, char *argv[])
{
	if (argc>=2)
	{
		int i;
		printf("  FILENAME\t     OWNER      GROUP\n");
		for(i=1;i<argc;i++) {
			struct stat info;
			char *file_path=argv[i];
			stat(file_path,&info);
			struct passwd *pw = getpwuid(info.st_uid);
			struct group  *gr = getgrgid(info.st_gid);			
			printf("%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
		}

	} else {
		printf("Who's Your Daddy: A commandline tool to find the owner:group of a file/folder.\nUsage:\twhosyodaddy <file path>\n");
	}
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include "color.h"

#define MAX_LENGTH 255

int main(int argc, char *argv[])
{
	if (argc>=2)
	{
		int i;
		colored_printer(stdout, BOLD_TEXT, "  FILENAME\t     OWNER      GROUP\n");
		for(i=1;i<argc;i++) {
			struct stat info;
			char *file_path=argv[i];
			stat(file_path,&info);
			struct passwd *pw = getpwuid(info.st_uid);
			struct group  *gr = getgrgid(info.st_gid);
			int file_type=-1;
			int exe=0;
			switch(info.st_mode & S_IFMT) {
		   		case S_IFBLK:  file_type=0;            break;
           		case S_IFCHR:  file_type=1;        break;
           		case S_IFDIR:  file_type=2;               break;
           		case S_IFIFO:  file_type=3;               break;
           		case S_IFLNK:  file_type=4;                 break;
           		case S_IFREG:  
           			file_type=5;
           			if(info.st_mode & S_IXUSR)
           				exe=1;
           			break;
           		case S_IFSOCK: file_type=6;                  break;
           		default:       file_type=-1;                break;
			}

			switch(file_type) {
				case 0:
					colored_printer(stdout, RED_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 1:
					colored_printer(stdout, YELLOW_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 2:
					colored_printer(stdout, CYAN_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 3:
					colored_printer(stdout, GREEN_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 4:
					colored_printer(stdout, BLUE_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 5:
					if(exe==0)
						colored_printer(stdout, REGULAR_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					else
						colored_printer(stdout, MAGENTA_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case 6:
					colored_printer(stdout, WHITE_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				case -1:
					colored_printer(stdout, RED_TEXT, "%10s\t%10s  %10s\n", file_path,pw->pw_name,gr->gr_name);
					break;
				default:
					colored_printer(stdout, RED_TEXT, "\n\nDont know how to handle: %s", file_path);
					break;
			}
		}

	} else {
		printf("Who's Your Daddy: A commandline tool to find the owner:group of a file/folder.\nUsage:\twhosyodaddy <file path>\n");
		printf("\nColor Guide:\n");
		colored_printer(stdout, RED_TEXT, "RED = Block File\n");
		colored_printer(stdout, YELLOW_TEXT, "YELLOW = Character File\n");
		colored_printer(stdout, CYAN_TEXT, "CYAN = Directory\n");
		colored_printer(stdout, GREEN_TEXT, "GREEN = FIFO File\n");
		colored_printer(stdout, BLUE_TEXT, "BLUE = Link File\n");
		colored_printer(stdout, REGULAR_TEXT, "REGULAR = Regular File\n");
		colored_printer(stdout, MAGENTA_TEXT, "MAGENTA = Executable File\n");
		colored_printer(stdout, WHITE_TEXT, "WHITE = Socket File\n\n");
	}
	return 0;
}
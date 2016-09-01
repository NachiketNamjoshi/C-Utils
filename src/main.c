#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

int main(int argc, char *argv[])
{
	int status=0,i=0;
	char *file_path=argv[1];
	char *command = "stat -c \"%U %G\" ";
	char *tmp = calloc(sizeof(file_path)+sizeof(command),sizeof(char));
	while(*command){
      tmp[i++]=*command++;
  }
  while(*file_path){
      tmp[i++]=*file_path++;
  }
  tmp[i]='\0';
	system(tmp);
	return 0;
}
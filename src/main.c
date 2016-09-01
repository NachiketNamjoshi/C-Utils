#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

int main()
{
	int status=0,i=0;
	char *file_path=malloc(sizeof(char)*MAX_LENGTH);
	char *command = "stat -c \"%U %G\" ";
	printf("Enter Path to file: \n");
	scanf("%s", file_path);
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
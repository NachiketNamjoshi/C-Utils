#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

int main()
{
	int status=0,i=0;
	char *file_path=malloc(sizeof(char)*MAX_LENGTH);
	printf("%f\n",sizeof(file_path));
	char *command = 'stat -c "%U %G" ';
	printf("%f\n", sizeof(command));
	printf("Enter Path to file: \n");
	scanf("%s", file_path);
	printf("Path to file: %s\n",file_path);
	char *tmp = malloc(sizeof(file_path)+sizeof(command));
	printf("%f\n", sizeof(tmp));
	while(*command){
      tmp[i++]=*command++;
  }
  while(*file_path){
      tmp[i++]=*file_path++;
  }
  tmp[i]='\0';
	printf("command: %s\n",tmp);
	system(command);
	return 0;
}
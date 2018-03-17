#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int file = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0777);
	if(file < 0){
		printf("Error");
		return 1;
	}//cierra if file
	if(write(file, argv[2],strlen(argv[2])) != strlen(argv[2])){
		printf("Error");
		return 1;
	}//cierra if write
	if(close(file) < 0){
		printf("Error");
		return 1;
	}//cierra if close
	return 0;
}//cierra main

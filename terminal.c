#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
       char* args = (char *) malloc(30);
       pid_t pid;
       printf("To exit write 'exit .' \nAdd a space after every parameter. \n");
       while(1){
               printf("$");
               fgets(args, 30, stdin);
               char* command = strtok(args, " ");
               char* param = strtok(NULL, " ");
               if(strcmp(command,"exit") == 0){
                       break;
               }//cierra if
               else{
                       pid = fork();
                       if(pid < 0){
                               printf("Error");
                               return 1;
                       }//cierra if error
                       else if(pid == 0){
				char path[5];
				strcpy(path, "/bin/");
				strcat(path, command);
                               execlp(path, command, param, NULL);
                       }//cierre else if child process
                       else{
                               wait(NULL);
                       }
               }//cierra else
       }//cierra while
       return 0;
}//cierra main

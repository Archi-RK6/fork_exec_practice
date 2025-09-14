#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int ret_1 = fork();

    if(ret_1 == 0){
        execl("/bin/ls", "ls", NULL);
        perror("execl 1");
        exit(1);
    } 

    int ret_2 = fork();

    if(ret_2 == 0){
        execl("/bin/date", "date", NULL);
        perror("execl 2");
        exit(1);
    }

    wait(NULL);
    wait(NULL);

    printf("Parent process done\n");
    return 0;
}
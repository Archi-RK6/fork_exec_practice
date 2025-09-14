#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();

    printf("PID = %d parent PID = %d\n \n", getpid(), getppid());
    sleep(60);
    return 0;
}
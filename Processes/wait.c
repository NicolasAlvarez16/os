#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int result = fork();

    if(result < 0){
        printf("fork call failed");
        exit(-1);
    }

    if(result != 0){
        wait(NULL);
        printf("Output ps:\n");
        execlp("ps", "ps");
    }
    else{
        printf("Output ls:\n");
        execlp("ls", "ls");
    }
}
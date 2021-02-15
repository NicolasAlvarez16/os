//A process is just a program that is executed by the OS
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    //Fork is a call to the OS to clone the current process
    int var = 1;
    int i;

    for(i = 0; i < 4; i++){
        if(fork() != 0){
            var++;
            break;
        }
        else{
            var += 2;
        }
    }
    printf("I am the %i process, my father is %i, the value is: %i\n", getpid(), getppid(), var);
}
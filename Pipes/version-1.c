#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char **argv){
    int pipe1[2]; //0 read, 1 write
    pipe(pipe1);
    char s[64];

    // int result = fork();
    if(fork()){
        // Father Process
    }
    else{
        // Child Process
    }
}
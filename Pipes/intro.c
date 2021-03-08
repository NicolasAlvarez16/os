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
        close(pipe1[1]);
        // read(pipe1[0], s, strlen(s));
        close(0);
        dup(pipe1[0]);
        close(pipe1[0]);
        // scanf("%s", s); // Shows it reads from standard input
        read(0, s, 64);
        // printf("I am the father process. I read from the descripto %d the the string: %s\n", pipe1[0], s);
        printf("I am the father process. I read from stdin the the string: %s\n", s);
    }
    else{
        // Child Process
        strcpy(s, "Hello World! OS Course");
        close(pipe1[0]);
        // write(pipe1[1], s, strlen(s));
        close(1);
        dup(pipe1[1]);
        close(pipe1[1]);
        // printf("I am the child prcess. I wrote from the descripto %d the the string: %s\n", pipe1[1], s);
        printf("%s\n", s);
    }
}
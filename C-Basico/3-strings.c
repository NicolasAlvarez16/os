#include<stdio.h>
#include<stdlib.h> //Para poder declarar punteros que apunten al heap
#include<string.h>

int main(){
    char *c = malloc(sizeof(char) * 6);
    strcpy(c,"Hello");

    printf("%s\n", c);
    free(c);
}
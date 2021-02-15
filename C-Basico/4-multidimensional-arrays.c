#include<stdio.h>
#include<stdlib.h> //Para poder declarar punteros que apunten al heap
#include<string.h>

int main(){
    char **strings = malloc(sizeof(char) *2); //Para tener un array a de arrays, necesitas un puntero apuntando a punteros **
    char *msg1 = malloc(sizeof(char) * 8);
    char *msg2 = malloc(sizeof(char) * 8);

    strcpy(msg1, "Hola");
    strcpy(msg2, "Mensaje");

    strings[0] = msg1;
    strings[1] = msg2;
    
    printf("%s\n", msg1);
    printf("%s\n", msg2);
}
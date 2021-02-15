#include<stdio.h>
#include<stdlib.h> //Para poder declarar punteros que apunten al heap

int main(){
    //int array[] = {1, 2, 3, 4, 5}; //Variables que estan dentro del stack -> El stack es una zona de memoria que pertenece  una fucnion
    /* El heap es la zona de memoria que te asigna el sistema donde vas a tener disponible acceso a todas las 
       variables y datos desde cualquier funcion, esto tienen que ser siempre punteros. */
    int length = 8;
    int *array = malloc(sizeof(int) * length); //malloc devulve una direccion de memoria que apunta al heap
    
    for(int i = 0; i < length; i++){
        array[i] = i + 1; //Desplazando el puntero en la memoria y anadiendo yn valor esa dirreccion
    }
    for(int i = 0; i < length; i++){
        printf("Valor de array[%d]: %d\n", i, array[i]);
    }
    free(array); //Es importatane liberar el espacio una vez que acaba el programa para evitar 'memory leaks'
}
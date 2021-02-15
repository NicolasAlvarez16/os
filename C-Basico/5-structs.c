#include<stdio.h>
#include<stdlib.h>

struct Punto{
    double x;
    double y;
};

int main(){
    struct Punto punto = malloc(sizeof(struct Punto));
    punto->x = 6.6;
    puny->y = 9.9;
    printf("c: %f, y: %f\n", punto->x, punto->y);
    free(punto);
    return 0;
}
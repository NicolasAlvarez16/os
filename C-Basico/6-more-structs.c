#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = malloc(sizeof(sizeof(struct Node)));
    head->next->value = 2;
    head->next->next = malloc(sizeof(sizeof(struct Node)));
    head->next->next->value = 3;

    printf("Dirreccion del primer nodo: %p\n", head);
    printf("Valor del primer nodo: %d\n", head->value);

    printf("Dirreccion del segundo nodo: %p\n", head->next);
    printf("Valor del segundo nodo: %d\n", head->next->value);

    printf("Dirreccion del tercer nodo: %p\n", head->next->next);
    printf("Valor del tercer nodo: %d\n", head->next->next->value);
}
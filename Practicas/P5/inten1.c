#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Pila {
    int top;
    unsigned capa;
    int* array;
};

// Funcion para crear una pila e iniciarla como 0
struct Pila* createStack(unsigned capa)
{
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->capa = capa;
    pila->top = -1;
    pila->array = (int*)malloc(pila->capa * sizeof(int));
    return pila;
}

// La pila esta llena cuando el tope es igual al ultimo indice
int isFull(struct Pila* pila)
{
    return pila->top == pila->capa - 1;
}

// La pila esta vacia cuando el tope es igual a -1
int isEmpty(struct Pila* pila)
{
    return pila->top == -1;
}

// Funcion para agregar un elemento a la pila. Incrementa el tope en 1
void push(struct Pila* pila, int in)
{
    if (isFull(pila))
        return;
    pila->array[++pila->top] = in;
    printf("%d\n", in);
}

// Funcion para quitar un elemento de la pila. Decrementa el tope en 1
int pop(struct Pila* pila)
{
    if (isEmpty(pila))
        return INT_MIN;
    return pila->array[pila->top--];
}

// Funcion para regresar el valor del tope de la pila sin quitarlo
int tope(struct Pila* pila)
{
    if (isEmpty(pila))
        return INT_MIN;
    return pila->array[pila->top];
}

// Funcion principal para probar las operaciones.
int main()
{
    struct Pila* pila = createStack(10);

    // Llenar la pila de mayor a menor
    for(int i=10; i>=1; i--) {
        push(pila, i);
    }

    int opcion = 0;
    while(opcion != 2) {
        printf("\n------ MENÚ ------\n");
        printf("1. Formarse\n");
        printf("2. Salir\n");
        printf("------------------\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        if(opcion == 1) {
            if(isEmpty(pila)) {
                printf("Lo siento, la pila de turnos esta vacia\n");
            } else {
                int turno = pop(pila);
                printf("El elemento se encuentra formado en la cola con el turno %d c:\n", turno);
            }
        } else if(opcion == 2) {
        printf("\nEstado de la pila:\n\n");
        if(isEmpty(pila)) {
            printf("La pila esta vacia\n");
        } else {
            printf("Tope de la pila: %d\n", tope(pila));
        }
        printf("Ultimo elemento de la cola: %d\n", pila->array[0]);
        }
    }
    return 0;
}

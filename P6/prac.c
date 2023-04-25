#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void enqueueFront(char *arr, char ch, int *pfront, int *prear) {
    if ((*prear + 1) % MAX == *pfront) {
        printf("\nLa cola esta llena. No se puede agregar el elemento.\n");
        return;
    }

    if (*pfront == -1)
        *pfront = *prear = 0;
    else
        *pfront = (*pfront - 1 + MAX) % MAX;

    arr[*pfront] = ch;
}

void enqueueRear(char *arr, char ch, int *pfront, int *prear) {
    if ((*prear + 1) % MAX == *pfront) {
        printf("\nLa cola esta llena. No se puede agregar el elemento.\n");
        return;
    }

    if (*pfront == -1)
        *pfront = *prear = 0;
    else
        *prear = (*prear + 1) % MAX;

    arr[*prear] = ch;
}

char dequeueFront(char *arr, int *pfront, int *prear) {
    char ch;

    if (*pfront == -1) {
        printf("\nLa cola esta vacia.\n");
        return '\0';
    }

    ch = arr[*pfront];
    arr[*pfront] = '\0';

    if (*pfront == *prear)
        *pfront = *prear = -1;
    else
        *pfront = (*pfront + 1) % MAX;

    return ch;
}

char dequeueRear(char *arr, int *pfront, int *prear) {
    char ch;

    if (*pfront == -1) {
        printf("\nLa cola esta vacia.\n");
        return '\0';
    }

    ch = arr[*prear];
    arr[*prear] = '\0';

    if (*pfront == *prear)
        *pfront = *prear = -1;
    else
        *prear = (*prear - 1 + MAX) % MAX;

    return ch;
}

void display(char *arr, int front, int rear) {
    int i;

    printf("\nContenido de la cola: ");
    for (i = front; i != rear; i = (i + 1) % MAX) {
        printf("%c ", arr[i]);
    }
    printf("%c", arr[rear]);
}

int isPalindrome(char *word) {
    int front = -1;
    int rear = -1;
    int length = strlen(word);

    // Agregar cada caracter de la palabra a la cola
    for (int i = 0; i < length; i++) {
        enqueueRear(word, word[i], &front, &rear);
    }

    // Revisar si la palabra es un palíndromo
    while (front != rear && front != (rear + 1) % MAX) {
        char frontChar = dequeueFront(word, &front, &rear);
        char rearChar = dequeueRear(word, &front, &rear);

        if (frontChar != rearChar) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char word[MAX];
    int isPalindromo;

        printf("Ingrese una palabra: ");
    scanf("%s", word);

    isPalindromo = isPalindrome(word);

    if (isPalindromo) {
        printf("Es PALINDROMO\n");
    } else {
        printf("NO es un PALINDROMO\n");
    }

    return 0;
}

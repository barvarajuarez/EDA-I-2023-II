#include <stdio.h>
#include <stdlib.h>

// Función para mostrar el menú de opciones 
int mostrarMenu() {
    int *opcion;
    printf("Menú de opciones:\n");
    printf("1. Reina\n");
    printf("2. Rey\n");
    printf("3. Salir\n");
    printf("Ingrese su elección: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función para solicitar las coordenadas x y y al usuario
void solicitarCoordenadas(int *x, int *y) {
    printf("Ingrese las coordenadas:\n");
    printf("x = ");
    scanf("%d", x);
    printf("y = ");
    scanf("%d", y);
}

// Función para imprimir el tablero y la pieza en las coordenadas especificadas
void imprimirTablero(int x, int y, int rango) {
    printf(" ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            if (i == x && j == y) {
                printf("R ");
            } else if ((abs(i - x) <= rango && j == y) || (abs(j - y) <= rango && i == x) || (abs(i - x) == abs(j - y) && abs(i - x) <= rango)) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int opcion;
    do {
        opcion = mostrarMenu();
        if (opcion == 1) {
            int x, y;
            solicitarCoordenadas(&x, &y);
            imprimirTablero(x, y, 7);
        } else if (opcion == 2) {
            int x, y;
            solicitarCoordenadas(&x, &y);
            imprimirTablero(x, y, 1);
        } else if (opcion != 3) {
            printf("Opción inválida\n");
        }
    } while (opcion != 3);

    return 0;
}
#include <stdio.h>

int main() {
    // Declarar el arreglo del tablero
    int tablero[8][8] = {0};

    // Pedir al usuario que indique la posición del alfil
    int ren, col;
    printf("Ingrese la posición del alfil (fila, columna): ");
    scanf("%d %d", &ren, &col);

    // Marcar la posición del alfil con una bandera
    tablero[ren][col] = 1;

    // Cuadrante 1
    int renC1 = ren-1, colC1 = col-1;
    while (renC1 >= 0 && colC1 >= 0) {
        tablero[renC1][colC1] = 2;
        renC1--;
        colC1--;
    }

    // Cuadrante 2
    int renC2 = ren-1, colC2 = col+1;
    while (renC2 >= 0 && colC2 <= 7) {
        tablero[renC2][colC2] = 2;
        renC2--;
        colC2++;
    }

    // Cuadrante 3
    int renC3 = ren+1, colC3 = col-1;
    while (renC3 <= 7 && colC3 >= 0) {
        tablero[renC3][colC3] = 2;
        renC3++;
        colC3--;
    }

    // Cuadrante 4
    int renC4 = ren+1, colC4 = col+1;
    while (renC4 <= 7 && colC4 <= 7) {
        tablero[renC4][colC4] = 2;
        renC4++;
        colC4++;
    }

    // Imprimir el tablero con los movimientos del alfil
    printf("\nMovimientos del alfil:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tablero[i][j] == 1) {
                printf(" A ");
            } else if (tablero[i][j] == 2) {
                printf(" * ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }

    return 0;
}

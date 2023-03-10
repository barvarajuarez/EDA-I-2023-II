#include <stdio.h>
#include <stdlib.h>

void pantalla (int x, int y, int r[][2], int t) {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            if (i == x && j == y) {
                printf("X ");
            } else {
                int v = 0;
                for (int k = 0; k < t; k++) {
                    if (r[k][0] == i && r[k][1] == j) {
                        v = 1;
                        break;
                    }
                }
                if (v) {
                    printf("* ");
                } else {
                    printf("- ");
                }
            }
        }
        printf("\n");
    }
}

void reina() {
    int x, y;
    printf("\nIngrese las coordenadas del alfil (x,y): ");
    scanf("%d,%d", &x, &y);
    int r[13][2];
    int t = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != x && j != y && abs(i - x) == abs(j - y)) {
                r[t][0] = i;
                r[t][1] = j;
                t++;
            }
        }
    }
    pantalla (x, y, r, t);
}

void rey() {
    int x, y;
    printf("\nIngrese las coordenadas de la torre (x,y): ");
    scanf("%d,%d", &x, &y);
    int r[14][2];
    int t = 0;
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            r[t][0] = i;
            r[t][1] = y;
            t++;
        }
    }
    for (int j = 0; j < 8; j++) {
        if (j != y) {
            r[t][0] = x;
            r[t][1] = j;
            t++;
        }
    }
    pantalla (x, y, r, t);
}

int main() {
    int op = 0;
    while (op != 3) {
        printf("\n\t---AJEDREZ---\n");
        printf("Menú:\n\n");
        printf("    1. Reina\n");
        printf("    2. Rey\n");
        printf("    3. Salir\n\n");
        printf("Ingrese su elección: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                reina();
                break;
                
            case 2:
                rey();
                break;
                
            case 3:
                break;
                
            default:
                printf("Opción no válida. Intente de nuevo. c: \n");
                break;
        }
    }
    return 0;
}
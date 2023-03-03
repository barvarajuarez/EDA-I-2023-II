#include <stdio.h>
#include <stdlib.h>

void pantalla (int x, int y, int range[][2], int size) {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            if (i == x && j == y) {
                printf("X ");
            } else {
                int valid = 0;
                for (int k = 0; k < size; k++) {
                    if (range[k][0] == i && range[k][1] == j) {
                        valid = 1;
                        break;
                    }
                }
                if (valid) {
                    printf("* ");
                } else {
                    printf("- ");
                }
            }
        }
        printf("\n");
    }
}

void alfil() {
    int x, y;
    printf("Ingrese las coordenadas del alfil (x,y): ");
    scanf("%d,%d", &x, &y);
    int range[13][2];
    int size = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != x && j != y && abs(i - x) == abs(j - y)) {
                range[size][0] = i;
                range[size][1] = j;
                size++;
            }
        }
    }
    pantalla (x, y, range, size);
}

void torre() {
    int x, y;
    printf("Ingrese las coordenadas de la torre (x,y): ");
    scanf("%d,%d", &x, &y);
    int range[14][2];
    int size = 0;
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            range[size][0] = i;
            range[size][1] = y;
            size++;
        }
    }
    for (int j = 0; j < 8; j++) {
        if (j != y) {
            range[size][0] = x;
            range[size][1] = j;
            size++;
        }
    }
    pantalla (x, y, range, size);
}
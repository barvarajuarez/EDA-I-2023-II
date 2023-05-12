#include <stdio.h>
#include <stdlib.h>

// Definición de las estructuras 
struct caballo {
    int x;
    int y;
};

struct ALFIL {
    int x;
    int y;
};

struct TORRE {
    int x;
    int y;
};

struct REINA {
    int x;
    int y;
};

struct REY {
    int x;
    int y;
};

// Función que pide al usuario las coordenadas del caballo y las guarda en una estructura
void pedirCoordenadasCA(struct caballo* coord) {
    printf("\nIngrese las coordenadas del caballo:\n");
    printf("Coordenada x: ");
    scanf("%d", &(coord->y));
    printf("Coordenada y: ");
    scanf("%d", &(coord->x));
}

// Función que pide al usuario las coordenadas del alfil y las guarda en una estructura
struct ALFIL pedir_coordenadasA() {
    struct ALFIL alfil;
    printf("\nIngrese las coordenadas del alfil:\n");
    printf("Coordenada x: ");
    scanf("%d", &alfil.y);
    printf("Coordenada y: ");
    scanf("%d", &alfil.x);
    return alfil;
}

// Función para pedir las coordenadas de la torre
struct TORRE pedir_coordenadasT() {
    struct TORRE torre;
    printf("\nIngrese las coordenadas de la torre:\n");
    printf("Coordenada x: ");
    scanf("%d", &torre.x);
    printf("Coordenada y: ");
    scanf("%d", &torre.y);
    return torre;
}

// Función para pedir las coordenadas de la reina
struct REINA pedir_coordenadas_reina() {
    struct REINA reina;
    printf("\nIngrese las coordenadas de la reina:\n");
    printf("Coordenada x: ");
    scanf("%d", &reina.y);
    printf("Coordenada y: ");
    scanf("%d", &reina.x);
    return reina;
}

// Función para pedir las coordenadas del rey
struct REY pedir_coordenadasREI() {
    struct REY rey;
    printf("\nIngrese las coordenadas del rey:\n");
    printf("Coordenada x: ");
    scanf("%d", &rey.y);
    printf("Coordenada y: ");
    scanf("%d", &rey.x);
    return rey;
}

// Función que muestra en una tabla los posibles movimientos del caballo de acuerdo a las coordenadas ingresadas
void mostrarPosiblesMovimientosCA(struct caballo coord) {
    int posiblesMovimientos[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int i, j;
    printf("\nPosibles movimientos del caballo:\n");
    printf("    1   2   3   4   5   6   7   8  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 1; i <= 8; i++) {
        printf("%d |", i);
        for (j = 1; j <= 8; j++) {
            if (i == coord.x && j == coord.y) {
                printf(" C |");
            } else {
                int k;
                int posible = 0;
                for (k = 0; k < 8; k++) {
                    if (i == coord.x + posiblesMovimientos[k][0] && j == coord.y + posiblesMovimientos[k][1]) {
                        posible = 1;
                        break;
                    }
                }
                if (posible) {
                    printf(" * |");
                } else {
                    printf("   |");
                }
            }
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Función para mostrar el tablero de ajedrez con las posiciones válidas del alfil
void mostrar_tableroA(struct ALFIL alfil) {
    int i, j;
    printf("\nPosibles movimientos del alfil:\n");
    printf("    0   1   2   3   4   5   6   7  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            struct ALFIL pos = {i, j};
            if (i == alfil.x && j == alfil.y) {
                printf(" A |"); // Alfil en su posición actual
            } else if (abs(i - alfil.x) == abs(j - alfil.y)) {
                printf(" * |"); // Posición válida del alfil
            } else {
                printf("   |"); // Posición vacía
            }
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}


// Función para mostrar el tablero de ajedrez con las posiciones válidas de la torre
void mostrar_tableroT(struct TORRE torre) {
    int i, j;
    printf("\nPosibles movimientos de la torre:\n");
    printf("    0   1   2   3   4   5   6   7  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            if ((i == torre.x) || (j == torre.y)) {
                if ((i == torre.x) && (j == torre.y)) {
                    printf(" T |"); // Torre en su posición actual
                } else {
                    printf(" * |"); // Posición válida de la torre
                }
            } else {
                printf("   |"); // Posición vacía
            }
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Función para mostrar el tablero de ajedrez con las posiciones válidas de la reina
void mostrar_tablero(struct REINA reina) {
    int i, j;
    printf("\nPosibles movimientos de la reina:\n");
    printf("    0   1   2   3   4   5   6   7  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            if ((i == reina.x || j == reina.y || abs(i - reina.x) == abs(j - reina.y)) && (i != reina.x || j != reina.y)) {
                printf(" * |"); // Posición válida de la reina
            } else if (i == reina.x && j == reina.y) {
                printf(" Q |"); // Reina en su posición actual
            } else {
                printf("   |"); // Posición vacía
            }
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Función para mostrar el tablero de ajedrez con las posiciones válidas del rey
void mostrar_tableroREI(struct REY rey) {
    int i, j;
    printf("\nPosibles movimientos del rey:\n");
    printf("    0   1   2   3   4   5   6   7  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            if ((abs(i - rey.x) == 1 && abs(j - rey.y) <= 1) || (abs(i - rey.x) <= 1 && abs(j - rey.y) == 1)) {
                if (i == rey.x && j == rey.y) {
                    printf(" K |"); // Rey en su posición actual
                } else {
                    printf(" * |"); // Posición válida del rey
                }
            } else {
                printf("   |"); // Posición vacía
            }
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Función principal
int main() {

    struct ALFIL alfil = {0, 0};
    struct TORRE torre = {0, 0};
    struct REY rey = {0, 0};
    struct REINA reina = {0, 0};

    int opcion;
    do {
        // Mostrar el menú 
        printf("\n\t---AJEDREZ---\n");
        printf("Menú:\n");
        printf("1. Caballo\n");
        printf("2. Alfil\n");
        printf("3. Torre\n");
        printf("4. Reina\n");
        printf("5. Rey\n");
        printf("6. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                struct caballo coord;
                pedirCoordenadasCA(&coord);
                mostrarPosiblesMovimientosCA(coord);
                break;
            }
            case 2:
                alfil = pedir_coordenadasA();
                mostrar_tableroA(alfil);
                break;
                
            case 3:
                
                torre = pedir_coordenadasT();
                mostrar_tableroT(torre);
                break;
                
            case 4:
                reina = pedir_coordenadas_reina();
                mostrar_tablero(reina);
                break;

            case 5:
                
                rey = pedir_coordenadasREI();
                mostrar_tableroREI(rey);
                break;

            case 6:
                break;

            default:
                printf("Opcion invalida. Intente de nuevo c:\n");
                break;
        }
    } while (opcion != 6);
    
    return 0;
}

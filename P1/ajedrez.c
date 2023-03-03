#include<stdio.h>

void crearMensaje();
void descifrarMensaje();

int main (){
    int opcion=0;

    while (1){
        printf("\n\t---AJEDREZ---\n");
        printf("¿Qué movimientos desear realizar?\n");
        printf("1) Alfil\n");
        printf("2) Torre\n");
        printf("3) Salir\n");
        scanf ("%d", &opcion);

        switch (opcion){
            case 1: 
                torre();
                break;
            case 2:
                alfil();
                break;
            case 3:
                return 0;
            default:
                printf("Opción no válida\n");
        }
    }
    return 0;
}

void alfil(){
    int equis, ye, i, j,k=0;
    printf("El tablero es de 8x8\n");
    printf("\n  Ingresa la coordenada x:");
    scanf("%i", &equis);
    printf("\n  Ingresa la coordenada y:");
    scanf("%i", &ye);

    char escitala[x][y];
    char texto [x*y];

    printf("Escriba el texto a cifrar: \n");
    scanf ("%s", texto);

    for (i=0; i<ren; i++)
        for (j=0; i<col; j++)
            escitala[i][j] = texto [k++];

    printf("El texto en la tira queda de la siguiente manera:\n");
    for (i=0; i<col; i++)
        for (j=0; i<ren; j++)
            escitala[i][j] = texto [k++];
                printf("%c", escitala[i][j]);
    printf("\n");
}

void torre(){
    int equis, ye, i, j, k=0;
     printf("El tablero es de 8x8\n");
    printf("\n  Ingresa la coordenada x:");
    scanf("%i", &equis);
    printf("\n  Ingresa la coordenada y:");
    scanf("%i", &ye);

    char escitala[ren][col];
    char texto[ren*col];

    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);

    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
            escitala[j][i] = texto[k++];
    printf("El texto descifrado es:\n");
    for (i=0 ; i<ren ; i++)
        for (j=0 ; j<col ; j++)
            printf("%c", escitala[i][j]);
}
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
    printf("\n  Coordenada x:");
    scanf("%i", &equis);
    printf("\n  Coordenada y:");
    scanf("%i", &ye);

    int rango[13][2];
    int tamaño=0;

    for (i=0; i<=8; i++){
        for (j=0; i<=8; j++){
            if (i!=equis && j!=ye && abs(i - equis) == abs (j - ye)){
                rango[tamaño][0] = i;
                rango[tamaño][1] = i;
                tamaño++;
            }
        }    
    }
    matriz(equis, ye, rango, tamaño);
}

void torre(){
    int equis, ye, i, j, k=0;
     printf("El tablero es de 8x8\n");
    printf("\n  Coordenada x:");
    scanf("%i", &equis);
    printf("\n  Coordenada y:");
    scanf("%i", &ye);

    int rango[14][2];
    int tamaño=0;

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

void matriz (){
    printf ("  1 2 3 4 5 6 7 8\n");
}
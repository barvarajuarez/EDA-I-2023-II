#include <sys/timeb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>                   // Libreria de utilidades de OpenGL
#include <GL/gl.h>
#include <GL/glu.h>


// Movimientos Reina -> movimientos torre + movimientos arfil
int** Movimientos_Reina(int *n_movs, int x, int pos_j_inicial)
{
  int **movs, **movs1, **movs2;
  int n_movs1=0, n_movs2=0, i;

  movs1=Movimientos_Torre(&n_movs1, x, pos_j_inicial);
  movs2=Movimientos_Arfil(&n_movs2, x, pos_j_inicial);

  *n_movs=n_movs1+n_movs2;

  if(*n_movs!=0) {
  movs = (int **) malloc (*n_movs * sizeof(int *));


  if(n_movs1!=0) {
  for(i=0;i<n_movs1;i++)
  	{
  	movs[i] = (int *) malloc(2*sizeof(int));
	movs[i][0] = movs1[i][0];
	movs[i][1] = movs1[i][1];
	free(movs1[i]);
	}
  free(movs1);
  } // end movs1

  if(n_movs2!=0) {
  for(i=0;i<n_movs2;i++)
  	{
  	movs[i+n_movs1] = (int *) malloc(2*sizeof(int));
	movs[i+n_movs1][0] = movs2[i][0];
	movs[i+n_movs1][1] = movs2[i][1];
	free(movs2[i]);
	}
  free(movs2);
  } // end movs2
  } // end movs principal

  return movs;
}


// Movimientos Rey -> en cualquier dirección pero de una sola casilla
int** Movimientos_Rey(int *n_movs, int pos_i_inicial, int pos_j_inicial)
{
  int movimientos[8][2];
  int **movs;
  int pos_i_final, pos_j_final, i;
  int color=tablero[pos_i_inicial][pos_j_inicial].color;
  
  // Movimiento al ESTE
  if(pos_j_inicial<7)
  	{
	pos_i_final=pos_i_inicial;
	pos_j_final=pos_j_inicial+1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}

  // Movimiento al OESTE
  if(pos_j_inicial>0)
  	{
	pos_i_final=pos_i_inicial;
	pos_j_final=pos_j_inicial-1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}
	
  // Movimiento al NORTE
  if(pos_i_inicial<7)
  	{
	pos_j_final=pos_j_inicial;
	pos_i_final=pos_i_inicial+1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}
	
  // Movimiento al SUR
  if(pos_i_inicial>0)
  	{
	pos_j_final=pos_j_inicial;
	pos_i_final=pos_i_inicial-1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}
	
  // Movimiento diagonal superior derecha
  if((pos_i_inicial<7)&&(pos_j_inicial<7))
  	{
	pos_i_final=pos_i_inicial+1;
	pos_j_final=pos_j_inicial+1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}

  // Movimiento diagonal inferior derecha
  if((pos_i_inicial>0)&&(pos_j_inicial<7))
  	{
	pos_i_final=pos_i_inicial-1;
	pos_j_final=pos_j_inicial+1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}

  // Movimiento diagonal inferior izquierda
  if((pos_i_inicial>0)&&(pos_j_inicial>0))
  	{
	pos_i_final=pos_i_inicial-1;
	pos_j_final=pos_j_inicial-1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}

  // Movimiento diagonal superior izquierda
  if((pos_i_inicial<7)&&(pos_j_inicial>0))
  	{
	pos_i_final=pos_i_inicial+1;
	pos_j_final=pos_j_inicial-1;
	if((tablero[pos_i_final][pos_j_final].ficha==LIBRE)||(tablero[pos_i_final][pos_j_final].color!=color))
		{
		movimientos[*n_movs][0]=pos_i_final;
		movimientos[*n_movs][1]=pos_j_final;
		*n_movs = *n_movs+1;
		}
	}

  if(*n_movs!=0) {
  movs = (int **) malloc (*n_movs * sizeof(int *));//printf("\n");
  for(i=0;i<*n_movs;i++)
  	{
  	movs[i] = (int *) malloc(2*sizeof(int));
	movs[i][0] = movimientos[i][0];
	movs[i][1] = movimientos[i][1];
	//printf("\n%d %d",movs[i][0],movs[i][1]);
	}
  }
  return movs;
}


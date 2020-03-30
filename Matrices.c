/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Matrices.c -o Matrices
Fecha: Tue Mar 24 02:11:43 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este programa calculará operaciones con 2 matrices y una constante cuyos valores serán dados por el usuario.
Entrada:  matA, matB, x
Salida:  Sum, const, Rest, Prod, Det, Inv, Trans, Gauss, GaussJ
*/

#include <stdio.h>
#include <math.h>


float main() 
{
	//Declaramos Variables
	int matA[3][3]; //La primera Matriz
	int matB[3][3]; //La segunda Matriz
	int matC[3][3]; //Una Matriz provisional para realizar operaciones
	float  matI[3][3]; //Otra Matriz Provisional
	int x, i, j, k, Prod, C, Det; //Variables para los ciclos for, y para operaciones varias
	int Suma = 0; //Variable para ciclos for


	printf("Por favor, ingrese los valores de la Matriz A.\n"); //Pedimos al usuario que ingrese los valores de su matriz A

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &matA[i][j]); //Con un loop for, vamos ingresando los valores del usuario en orden. 
						//Primero las columnas, luego las filas.
		}
	}


	
	printf("\nPor favor, ingrese los valores de la Matriz B.\n"); //Repetimos el proceso con la segunda matriz.

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &matB[i][j]);
		}
	}


	printf("\nPor favor, ingrese una constante.\n"); //Pedimos una constante
	scanf("%d", &x); //Escaneamos la constante.



		//MOSTRANDO LAS DOS MATRICES AL USUARIO

	printf("\nMatriz A:\n"); //Mostramos las matrices en una forma más familiar, de filas y columnas, para facilitar la orientación.
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j]);

			if(j==2)
			{
				printf("\n"); //Si se llega a la tercera columna (posición j igual a dos), se imprimirá una nueva fila.
			}
		}
	}

			
	printf("\nMatriz B:\n"); //Realizamos lo mismo con la matriz 2

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matB[i][j]);

			if(j==2)
			{
				printf("\n");
			}
		}
	}		


	
		//PARTE UNO: MULTIPLICACIÓN POR ESCALAR


	printf("\nMultiplicación de la Matriz A por %i:\n", x); //Enunciado para el usuario. 

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", x*matA[i][j]); //Procedemos a imprimir las componentes de la matriz, multiplicadas por la constante.

			if(j==2)
			{
				printf("\n"); //Imprimimos nueva línea.
			}
		}
	}



			//PARTE DOS: SUMA DE A CON B


	printf("\nSuma de la Matriz A con la Matriz B:\n"); //Enunciado para el usuario.

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j] + matB[i][j]); //Imprimimos el resultado de sumar las componentes de ambas matrices.
								//Yendo de i-ésima fila y j-ésima columna.
			
			if(j==2)
			{
				printf("\n"); //Imprimimos nueva fila.
			}
		}
	}

	
		
			//PROBLEMA TRES: RESTA DE A CON B

	printf("\nResta de la Matriz B a la Matriz A:\n"); //Enunciado para el usuario.
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j] - matB[i][j]); //Imprimimos los resultados de las restas.

			if(j==2)
			{
				printf("\n"); //Imprimimos nueva fila.
			}
		}
	}




		//PARTE CUATRO: PRODUCTO DE LA MATRIZ A CON LA MATRIZ B

	printf("\nProducto de la Matriz A con la Matriz B:\n"); //Enunciado para el usuario.

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
		
			for(k = 0; k < 3; k++) //Hacemos 3 loops, debido a cómo funciona el algoritmo de multiplicación. 
			{
				Prod =  matA[i][k]*matB[k][j]; //Multiplicamos fila con columna (por eso se matA tiene i y matB tiene j)

				Suma = Suma + Prod; //Procedemos a sumar los productos, como se hace en esta operación de matrices.
			}


			matC[i][j] = Suma; //Una vez se hayan sumado los productos, el valor se asigna a la ij-ésima componente de la matriz A.
					//Repetimos eso para todas las i y j.			
			Suma = 0; //Reseteamos Suma para el siguiente proceso en k.
		}
	}



	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matC[i][j]); //Procedemos a imprimir las componentes de nuestra matriz provisional C.
			
			if(j==2)
			{
				printf("\n"); //Imprimimos nueva línea.
			}
		}
	}



		//PARTE CINCO: DETERMINANTE DE LA MATRIZ A
		
	printf("\nDeterminante de la Matriz A:\n"); //Enunciado para el usuario.
	
	//Realizamos las operaciones correspondientes a cada componente del determinante. 
	float Det1 = matA[0][0]*(matA[1][1]*matA[2][2] - matA[1][2]*matA[2][1]);
	float Det2 = matA[0][1]*(matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2]);
	float Det3 = matA[0][2]*(matA[1][0]*matA[2][1] - matA[1][1]*matA[2][0]);

	Det = Det1 + Det2 + Det3; //Sumamos las componentes en una sola variable.

	printf("%d\n", Det); //Imprimimos el determinante.
	


		//PARTE SEIS: MATRIZ TRANSPUESTA DE B
	
	printf("\nMatriz B Transpuesta:\n"); //Enunciado para el usuario.

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matB[j][i]); //Hacemos el mismo loop for de siempre, pero invertimos i con j, para generar la transpuesta.

			if(j==2)
			{
				printf("\n"); //Imprimimos nueva línea.
			}
		}
	}



		//PARTE SIETE: MATRIZ INVERSA DE A

	printf("\nMatriz A Inversa:\n"); //Enunciado para el usuario.
	
	if(Det==0)
	{
		printf("La Matriz A no es Invertible\n"); //Mensaje para el usuario. Cuando el determinante es cero, la matriz no tiene inversa.
		//Esto es bien sabido en matemática, pero además la condicional impide que acabemos dividiendo entre cero.
	}

	else
	{
//El proceso usado para encontrar la inversa es la de dividir la matriz adjunta entre el determinante. 
		
		//Sacamos cada una de las 9 componentes de la matriz adjunta.
		matI[0][0] = matA[1][1]*matA[2][2] - matA[1][2]*matA[2][1];	
		matI[0][1] = matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2];	
		matI[0][2] = matA[1][0]*matA[2][1] - matA[1][1]*matA[2][0];	
		matI[1][0] = matA[0][2]*matA[2][1] - matA[0][1]*matA[2][2];	
		matI[1][1] = matA[0][0]*matA[2][2] - matA[0][2]*matA[2][0];	
		matI[1][2] = matA[0][1]*matA[2][0] - matA[0][0]*matA[2][1];	
		matI[2][0] = matA[0][1]*matA[1][2] - matA[0][2]*matA[1][1];	
		matI[2][1] = matA[0][2]*matA[1][0] - matA[0][0]*matA[1][2];	
		matI[2][2] = matA[0][0]*matA[1][1] - matA[0][1]*matA[1][0];	
	
		for(i = 0; i <= 2; i++)
		{
			for(j = 0; j <= 2; j++)
			{
				
				printf("%f\t", matI[j][i]/Det); //Finalmente, con este loop for, imprimimos el resultado de dividir la ij-ésima componente de la matriz, entre el Determinante.
 
				if(j==2)
				{
					printf("\n"); //Imprimimos nueva línea.
				}
			}
		}
	}
	


			//PARTE OCHO: REDUCCIÓN DE GAUSS

	printf("\nMatriz A reducida con Gauss:\n"); //Enunciado para el usuario.

	
	for(i = 0; i < 3; i++) //Loop for para imprimir la matriz.
	{
		for(j = 0; j < 3; j++)
		{
			if(i==j)
			{
				printf("1\t"); //La diagonal siempre son unos.
			}

			else if(i > 0 && j < i )
			{
				printf("0\t"); //Abajo de la diagonal hay ceros.
			}

			else
			{
				printf("%d\t", matA[i][j]);
			}
			
			if(j==2)
			{
				printf("\n"); //Imprimimos nueva línea.
			}
		}
	}



	//PROBLEMA NUEVE: REDUCCIÓN DE GAUSS-JORDAN

	
	printf("\nMatriz A reducida por Gauss-Jordan:\n"); //Enunciado para el usuario.

	for(i = 0; i < 3; i++) //Loop for para encontrar la matriz reducida.
	{
		for(j = 0; j < 3; j++)
		{
			if(j==i)
			{
				printf("1\t"); //La diagonal son siempre unos.
			}
		
			else
			{ 
				printf("0\t"); //Todo lo demás es igual a cero.
			}

			if(j==2)
			{
				printf("\n"); //Imprimimos nueva línea.
			}
		}
	}




return 0;

}


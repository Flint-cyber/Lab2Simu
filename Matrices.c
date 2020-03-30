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

//Incluir librerias
#include <stdio.h>
#include <math.h>


float main()
{
	int matA[3][3];
	int matB[3][3];
	int matC[3][3];
	float  matI[3][3];
	int x, i, j, k, Prod, C, Det;
	int Suma = 0;


	printf("Por favor, ingrese los valores de la Matriz A.\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &matA[i][j]);
		}
	}


	
	printf("\nPor favor, ingrese los valores de la Matriz B.\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &matB[i][j]);
		}
	}


	printf("\nPor favor, ingrese una constante.\n");
	
	scanf("%d", &x);



		//MOSTRANDO LAS DOS MATRICES AL USUARIO

	printf("\nMatriz A:\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j]);

			if(j==2)
			{
				printf("\n");
			}
		}
	}

			
	printf("\nMatriz B:\n");

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


	printf("\nMultiplicación de la Matriz A por %i:\n", x);

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", x*matA[i][j]);

			if(j==2)
			{
				printf("\n");
			}
		}
	}



			//PARTE DOS: SUMA DE A CON B


	printf("\nSuma de la Matriz A con la Matriz B:\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j] + matB[i][j]);
			
			if(j==2)
			{
				printf("\n");
			}
		}
	}

	
		
			//PROBLEMA TRES: RESTA DE A CON B

	printf("\nResta de la Matriz B a la Matriz A:\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matA[i][j] - matB[i][j]);

			if(j==2)
			{
				printf("\n");
			}
		}
	}




		//PARTE CUATRO: PRODUCTO DE LA MATRIZ A CON LA MATRIZ B

	printf("\nProducto de la Matriz A con la Matriz B:\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
		
			for(k = 0; k < 3; k++)
			{
				Prod =  matA[i][k]*matB[k][j];

				Suma = Suma + Prod;
			}


			matC[i][j] = Suma;
			
			Suma = 0;
		}
	}



	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matC[i][j]);
			
			if(j==2)
			{
				printf("\n");
			}
		}
	}



		//PARTE CINCO: DETERMINANTE DE LA MATRIZ A
		
	printf("\nDeterminante de la Matriz A:\n");

	float Det1 = matA[0][0]*(matA[1][1]*matA[2][2] - matA[1][2]*matA[2][1]);
	float Det2 = matA[0][1]*(matA[1][2]*matA[2][0] - matA[1][0]*matA[2][2]);
	float Det3 = matA[0][2]*(matA[1][0]*matA[2][1] - matA[1][1]*matA[2][0]);

	Det = Det1 + Det2 + Det3;

	printf("%d\n", Det);



		//PARTE SEIS: MATRIZ TRANSPUESTA DE B
	
	printf("\nMatriz B Transpuesta:\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", matB[j][i]);

			if(j==2)
			{
				printf("\n");
			}
		}
	}



		//PARTE SIETE: MATRIZ INVERSA DE A

	printf("\nMatriz A Inversa:\n");
	
	if(Det==0)
	{
		printf("La Matriz A no es Invertible\n");
	}

	else
	{

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
				
				printf("%f\t", matI[j][i]/Det);

				if(j==2)
				{
					printf("\n");
				}
			}
		}
	}
	


			//PARTE OCHO: REDUCCIÓN DE GAUSS

	printf("\nMatriz A reducida con Gauss:\n");

	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(i==j)
			{
				printf("1\t");
			}

			else if(i > 0 && j < i )
			{
				printf("0\t");
			}

			else
			{
				printf("%d\t", matA[i][j]);
			}
			
			if(j==2)
			{
				printf("\n");
			}
		}
	}



	//PROBLEMA NUEVE: REDUCCIÓN DE GAUSS-JORDAN

	
	printf("\nMatriz A reducida por Gauss-Jordan:\n");

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(j==i)
			{
				printf("1\t");
			}
		
			else
			{
				printf("0\t");
			}

			if(j==2)
			{
				printf("\n");
			}
		}
	}




return 0;

}


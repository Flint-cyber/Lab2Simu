/*
Autor: josec
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc MC.c -o MC
Fecha: Wed Apr 22 07:14:53 CST 2020
Librerias: stdio, otras librerias
Resumen: Este programa calcula una recta por medio del método de mínimos cuardados
Entrada: 
Salida: m, b, dm, db
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Declaramos Variables

float Vol[6] = {54.3, 61.8, 72.4, 88.7, 118.6, 194.0};
float Pre[6] = {61.2, 49.2, 37.6, 28.4, 19.2, 10.2};
int i; 
float m, b, dm, db, r;
float sum1, sum2, sum3, sum4;


float M (float n1, float n2, float n3, float n4);
float B (float n2, float n3, float n);
float DM (float n4, float n3);


void main(void)
{

	db = 0.1/sqrt(6);

	for(i = 0; i < 6; i++)
	{
		sum1 = sum1 + Vol[i]*Pre[i];

		sum2 = sum2 + Vol[i];
		
		sum3 = sum3 + Pre[i];

		sum4 = sum4 + Vol[i]*Vol[i];
	}


	printf("Volumen\t\t\tPresión\n");
	
	for(i = 0; i < 6; i++)
	{
		printf("%.1f +- 0.1\t\t%.1f +- 0.2\n", Vol[i], Pre[i]);
	}

	m = M(sum1, sum2, sum3, sum4);
	printf("\nPendiente m:\t");
	printf("%.4f\n", m);

	
	b = B(sum2, sum3, m);
	printf("\nIntersecto b:\t");
	printf("%.2f\n", b);

	dm = DM(sum2, sum4);
	printf("\nIncerteza en m:\t%.4f\n", dm);

	printf("\nIncerteza en b:\t%.2f\n", db);

	printf("\nEcuación de Recta:\t");
	printf("y = (%.4f +- %.4f)x + (%.2f +- %.2f)\n\n", m, dm, b, db);

	printf("Valor estimado de Presión con V = 100:\t");
	printf("%.1f\n", 100*m + b);



	//IMPRESIÓN DE LA GRÁFICA
	
	FILE * pun1;
	FILE * pun2;
	
	pun1 = fopen("plot1.txt", "w");

	for(i = 0; i < 6; i++)
	{
		fprintf(pun1, "%.1f\t%.1f\n",Vol[i], Pre[i]);
	}

	fclose(pun1);

	pun2 = fopen("squares.gp", "w");
	fprintf(pun2, "plot %.2f*x + %.2f lw 4, 'plot1.txt' lw 4;", m, b);
	fclose(pun2);

	system("gnuplot -p squares.gp");


	remove("plot1.txt");
	remove("squares.gp");



}




float M (float n1, float n2, float n3, float n4)
{
	float res, num, den;

	num = 6*n1 - n2*n3;
	den = 6*n4 - n2*n2;
	
	res = num/den;

	return res;
}



float B (float n2, float n3, float n)
{
	float res, num, den;
	
	num = n3 -n*n2;
        
	res = num/6;

	return res;
}



float DM (float n2, float n4)
{
	float res;

	res = sqrt(6)*0.1/pow(6*n4 -n2*n2, 0.5);

	return res;
}


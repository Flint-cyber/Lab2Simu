/*
Autor: geotoj
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc Taylor.c -o taylor
Fecha: mar abril 21 2020
Librerias: stdio.h, math.h
Resumen: Este programa aproxima la solución de una EDO de tres maneras diferentes.
Entrada: -
Salida:  soluciones
*/

//Incluimos las librerías
#include <stdio.h>
#include <math.h>

//Definimos las funciones
float Fun (float y, float t); //Función dy/dt
float Medio (float a, float b); //Función del Punto Medio
float Euler (float a, float b);//Función de Euler Modificado
float Heun (float a, float b);//Función de Heun

int i; //Variable de iteración
int n = 10; //Número de pasos que haremos en los métodos


//Iniciamos la función principal
void main(void)
{
    //Declaramos variables
	float a= 0; //cota inferior
	float b = 2; //cota superior
	float w = 0.5; //Valor inicial de y


    //Enunciamos al usuario de qué trata el programa.
	
    	printf("Queremos resolver la E.D.O.:\n");

	printf("\ny' = y - t^2 +1 en el intervalo [0,2]\n");
	
	printf("Con solo 10 iteraciones\n");

	//Procedemos a imprimir todas las soluciones en orden
	printf("\nSolución usando Punto Medio:\ty = ");

	printf("%f\n", Medio(a, b));

	printf("Solución usando Euler:\t\ty = ");

	printf("%f\n", Euler (a, b));

	printf("Solución usando Heun:\t\ty = ");

	printf("%f\n\n", Heun (a, b));
}



//Iniciamos la función de la EDO
float Fun(float t, float y)
{
    float res; //Variable del resultado
    
    res = y - pow(t,2) + 1; //Esta es la función f(x,t) que usaremos

    return res; //Al terminar, retornamos el resultado
}


		//CALCULANDO LOS MÉTODOS NUMÉRICOS



//Iniciamos la función del Método del Punto Medio
float Medio (float a, float b)
{
	//Declaramos variables locales
	float h, t, w, y; 
    
	h = (b - a)/n; //h define cómo de largos van a ser los pasos
	t = a; //Iniciamos en el tiempo cero
	w = 0.5; //Tenemos el valor inicial de w para referencia
    
	
	//Creamos un loop for para el proceso iterativo
	for (i = 1; i <= 10; i++)
    	{   
		//Generamos unas variables para simplificar el código
		float k1 = w + (h/2)* Fun(t, w); 
		
		float k2 = t + h/2;

        	//Realizamos la suma iterativa de w
              	w = w + h*Fun (k2, k1);

		//Aumentamos el tiempo con la información dada por h
		t = t + h;
        	
		//Le asignamos el valor de w a y, nuestro resultado
		y = w;

    	}
    	
	return y; //Retornamos y a la función principal
}



//Iniciamos la función del método de Euler
float Euler (float a, float b)
{
	//Declaramos variables locales
	float h, t, w, y;

	h = (b - a)/n;
	t = a;
	w = 0.5;

	
	//Comenzamos el loop iterativo
	for(i = 0; i < n; i++)
	{
		//Primera variable simplificada
		float k1 = Fun (t, w);
		
		//Segunda variable simplificada
		float k12 = w + h*k1;
		
		//Aumentamos en una unidad el tiempo
		//Debido a que la siguiente variable necesita un t + 1
		t = t + h;
		
		//Tercera variable simplificada
		float k2 = Fun (t, k12);

		//Realizamos el cálculo y suma iterativa de w
		w = w + 0.5*h*(k1 + k2);

		//Asignamos el valor de w a y
		y = w;

	}

	return y;
}



//Iniciamos la función de Heun
float Heun (float a, float b)

{
	//Declaramos variables locales
	float h, t, w, y;

	h = (b - a)/n;
	t = a;
	w = 0.5;


	//Iniciamos el proceso iterativo
	for(i = 0; i < n; i++)
	{

		//Variable simple 1		
		float k1 = Fun (t, w);
		
		//Variable simple 2
		float k2 = w + (2*h/3)*k1;

		//Variable simple 3
		float k3 = t + (2*h/3);

		//Cálculo y suma iterativa de w
		w = w + (h/4)*(k1 + 3*Fun(k3, k2));

		//Aumentamos el tiempo en una unidad
		t = t + h;

		//Le asignamos el valor de w a y
		y = w;

	}
	
	return y;
}


		






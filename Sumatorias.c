/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Factoriales.c -o Factoriales
Fecha: Mon Mar 23 20:27:22 UTC 2020
Librerias: stdio, math
Resumen: Este programa calcula el resultado de cuatro sumatorias distintas, desde un número inicial, hasta un número final dado por el usuario.
Entrada:  num
Salida:  suma, sumb, sumc, sumd
*/

#include <stdio.h>
#include <math.h>




double Sumac (int n) //Función de recursividad para la tercera sumatoria. 
	
{

	if(n==1)
	{
		return 1; //El valor de n igual a uno, es uno. Usamos esto como base para construir el primer bloque de la relación de recursividad.
	}

	else //Si el valor de n no es uno, entonces procedemos a decrecer el número hasta que este sea uno. 
		//A partir de este punto, vamos en reversa, valuando la sumatoria e incrementando el valor de n hasta que sea el que eligió el usuario.
		//Finalmente, regresamos el valor final de la sumatoria.
	{
		return ( pow(5, -0.5)*(pow(0.5,n)*( (pow(1+sqrt(5),n) - (pow(1-sqrt(5),n)))) + pow(0.5, n - 1)*(pow(1 + sqrt(5), n-1) - pow(1-sqrt(5), n-1))));
	}

}




double main() //Función main double, ya que no estamos trabajando exclusivamente con enteros.

{

	int num; //Variable de entrada
	int k; //Variable de control para nuestros loops.
	double suma, sumb, sumc, sumd; //Variables de salida. Una para cada sumatoria. 


	printf("Por favor, ingrese un entero positivo.\n"); //Le pedimos al usuario que elija hasta donde quiere que se sume.
	scanf("%d", &num); //Escaneamos la entrada y le asignamos el valor a la variable num.



	while(num < 1) //Este loop hará que no se acepten números menores a uno, ya que desde ahí parten muchas de nuestras sumatorias.
	{
		printf("El número que ingresó no es válido\n\nPor favor, ingrese un número.\n"); //Se seguirá escaneando hasta conseguir un número mayor o igual a uno.
		scanf("%d", &num);
	}



	//PRIMERA SUMATORIA
	
	if(num <=3) //Nuestra primera sumatoria no empieza realmente sino hasta el número cuatro. 
	{
		printf("\nLa Primera Sumatoria no es Válida en este número\n"); 
		//Sin embargo, no queremos que esto interrumpa nuestro programa. 
		//Así que solo imprimiremos una pequeña notificación de error, y seguiremos con la siguiente sumatoria.
	}

	else //En caso de cumplir con el criterio, realizamos la primera sumatoria.
	{
		suma = 0; //Inicializamos nuestra variable de recurrencia en 0, para usarla después.

		for(k = 4; k <= num; k++) //Realizamos la sumatoria con un loop for, cuya variable k empieza en 4, y termina en el número dado por el usuario.
		{
			suma = suma + pow(k, 2)*(k - 3);//La fórmula de esta primera sumatoria es sencilla: elevando k al cuadrado y multiplicándolo por k menos tres.
			//No obstante, para que se vayan añadiendo cada vez nuevos términos, la variable suma debe igualarse a ella misma MÁS el nuevo término.
			//Y, como no hay término antes de k igual a uno, lo designamos como cero en la inicialización. Lo mismo en las siguientes sumatorias.
		}

		printf("\nResultado de la Primera Sumatoria: %f\n", suma); //Finalmente, imprimimos el resultado.
	}





	//SEGUNDA SUMATORIA

	if(num == 1)
	{
		printf("\nLa Segunda Sumatoria tiende a Infinito\n"); //De nuevo, esta sumatoria no inicia en uno-
		//Nos encargamos de notificar al usuario, en caso de haber ingresado el número uno, antes de continuar a la siguiente.
	}
	
	else //De lo contrario, se realiza la sumatoria.
	{
		sumb = 0; //Inicializamos la variable de recursividad en cero.

		for(int k = 2; k <= num; k++) //Empezamos nuestro loop con k desde cero hasta num.
		{
			sumb = sumb + 3*pow(k - 1, -1);  //La sumatoria requiere del uso de la función power, para poder colocar k menos uno como una fracción.
		}


		printf("\nResultado de la Segunda Sumatoria: %f\n", sumb); //Imprimimos la segunda sumatoria.
	}



	//TERCERA SUMATORIA
	
	//Para esta, sí utilizamos una función de recursividad propiamente, llamada Sumac, y que ya se vio arriba en el programa.
	
	sumc =  Sumac(num); //Nuestra variable sumc será igualada al resultado de la función recursiva Sumac, cuando se le valúa con el número del usuario.

	printf("\nResultado de la Tercera Sumatoria: %f\n", sumc); //Imprimimos la tercera sumatoria.



	//CUARTA SUMATORIA
	
	if(num==1) //Otra condicional, dado que esta sucesión de Bode empieza solo hasta el número 2. 
	{
		printf("\nLa Cuarta Sumatoria no es válida en este número.\n"); //Notificamos al usuario.
	}

	else
	{
		sumd = 0; //Inicializamos la variable de recursividad.

		for(int k = 2; k <= num; k++)
		{
			sumd = sumd + 0.1*(3*pow(2,k-2) + 4); //Realizamos la sumatoria, haciendo uso de la función power.
		}

		printf("\nResultado de la Cuarta Sumatoria: %f\n", sumd); //Imprimimos la cuarta sumatoria.
	}



return 0;

}



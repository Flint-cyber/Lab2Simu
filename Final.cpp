
//Incluimos librerías
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Empezamos inicializando la clase: Proyectil
class Proyectil
{
    private: 
        double empuje, cons, coef, A, mo, mfo; //Atributos
    public:
        Proyectil (long double, long double, long double, long double, long double, long double); //COnstructor
        //Métodos
        double mc(); //Variación masa
        double G(); //Aceleración Gravitatoria
        double F(); //Fricción atmosférica
        double rho(); //Densidad del aire
        double Y(); //Posición en y
        double V(); //VElocidad en y
        double time(); //TIempo
};


//COnstructor
Proyectil::Proyectil(long double _empuje, long double _cons, long double _coef, long double _A, long double _mo, long double _mfo)
{
    empuje = _empuje;
    cons = _cons;
    coef = _coef;
    A = _A;
    mo = _mo;
    mfo = _mfo;


}

//Fórmula para encontrar el tiempo en que se queda sin combustible
double Proyectil::time()
{
    double T;

    T = mfo/(empuje*cons);

    printf("Tardará %.1fs en quedarse sin combustible\n\n", T);

    return T;
}

//FOrmula para calcular la aceleración gravitatoria
double Proyectil::G()
{
    const long double g = 6.674e-11;
    const long double Mt = 5.9736e24;
    const long double Rt = 6.378e6;
    double acc;
    

    acc = (g*Mt)/pow(2, Rt + Y());
     
     return acc;

}

//Fórmula para calcular la densidad
double Proyectil::rho()
{
    const long double Po = 101325;
    const long double L = 6.5e-3;
    const long double R = 287.06;
    const long double To = 288.15;
    const long double go = 9.81;
    double rho;

    if(Y() > To/L)
    {
        rho = 0;
    }

    else
    {
     
     rho = (Po/(R*To))*pow(go/(R*L), 1 - (L*Y()/To));

    }

    return rho;
}


//Fórmula para calcular la masa del cohete
double Proyectil::mc()
{
    double mf, mc;
    double delta = 0.1;

    for(int i = 0; i < 20; i++)
    {
        mf = mf -empuje*cons*delta;

    }

    mc = mo + mf;

    return mc;

}


//FOrmula para calcular la fricción del cohete
double Proyectil::F()
{
    double fric;

    fric = 0.5*coef*A*rho()*V()*abs(V());

    return fric;
}


//FOrmula para calcular la velocidad que alcanza el cohete.
double Proyectil::V()
{

    double v;
    double delta = 0.1;

    for(int i = 1; i < 10; i++)
    {
        v+= delta*(empuje - G() - (F()/mc()));

        cout<<v<<endl;
    }

    return v;
    
}


//Formula para calcular la trayectoria del cohete
double Proyectil::Y()
{

    double P[10];
    double y;
    double delta = 0.1;

    for(int i = 1; i < 10; i++)
    {

        y += delta*V();
        P[i] = delta*V();

    }


//Impresión de Gráfica
    FILE *tabla;//Puntero para el txt tabulado
    FILE *plot; //PUntero para el .gpp de gnuplot

    tabla = fopen("tab.txt", "w");
    for(int i = 0; i < 10; i++)
    {
        fprintf(tabla, "%f\t%i\n", P[i], i);
    }
    fclose(tabla);

    plot = fopen("plot.gp", "w");
    fprintf(plot, "plot tabla.txt;");
    fclose(plot);

    system("gnuplot -p tabla.gp");

    remove("plot.txt");
    remove("tabla.gp");

    
    return y;
        
}



//Función principal
int main()
{
    
    Proyectil P1(3e7, 3.248e-4, 61.27, 201.6, 1.1e5, 1.5e6);
    Proyectil P2(2.7e7, 2.248e-4, 61.27, 201.06, 1.1e5, 1.5e6);
    Proyectil P3(2.5e7, 2.248e-4, 70.25, 215, 1.8e5, 2.1e6);

    cout<<"Proyectil 1:"<<endl;    
    P1.time();

    cout<<"Proyectil 2:"<<endl;
    P2.time();

    cout<<"Proyectil 3:"<<endl;
    P3.time();
        
    P1.Y();
    P2.Y();
    P3.Y();

return 0;

}











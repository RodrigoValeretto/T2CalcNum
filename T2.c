#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxD2 (double)(2/exp(1))
#define maxD4 (double)12.0

double majoranteErroS()
{
    double res = pow((90*(pow(10, -8)))/maxD4, 1.0/5.0);
    return res;
}

int calcunaN(double maj)
{
    int res = (1.0/maj);
    res++;
    return res;
}

double majoranteErroT()
{
    double res = pow((12*(pow(10, -8)))/maxD2, 1.0/3.0);
    return res;
}

double FormulaTrapezio(int NT, double h1)
{
    double soma = 0;
    for(int i = 1; i <= NT; i++)
    {
        double x0 = (i-1)*h1;
        double x1 = (i*h1);
        x0 = -pow(x0,2);
        x1 = -pow(x1,2);
        soma  = soma + (h1/2)*(exp(x0) + exp(x1));
    }

    return soma;
}

double FormulaSimpson(int NS, double h2)
{
    double soma = 0;
    for(int i = 2; i <= NS; i+=2)
    {
        double x0 = (i-2)*h2;
        double x1 = ((i-1)*h2);
        double x2 = (i*h2);
        x0 = -pow(x0,2);
        x1 = -pow(x1,2);
        x2 = -pow(x2,2);
        soma  = soma + (h2/3)*(exp(x0) + 4*exp(x1) + exp(x2));
    }

    return soma;
}

int main()
{
    //***PARTE 1***//
    double maj1 = majoranteErroT();
    int  NT = calcunaN(maj1);

    double maj2 = majoranteErroS();
    int NS = calcunaN(maj2);

    printf("NT = %d\n", NT);
    printf("NS = %d\n", NS);


    //***PARTE 2***//
    double h1 = 1.0/NT;
    double h2 = 1.0/NS;

    printf("Maj1 = %.8lf\n", h1);
    printf("Maj2 = %.8lf\n", h2);

    double res = FormulaTrapezio(NT, h1);
    printf("Res1 = %.8lf\n", res);

    double res2 = FormulaSimpson(NS, h2);
    printf("Res2 = %.8lf\n", res2);
}
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

double FormulaTrapezioRep(int NT, double h1)
{
    double x0 = (0*h1);
    x0 = -pow(x0,2);
    double xn = (NT*h1);
    xn = -pow(xn, 2);
    double xj;
    double somatorio = 0;

    for(int j = 1; j < NT; j++)
    {
        xj = (j*h1);
        xj = -pow(xj, 2);

        somatorio = somatorio + exp(xj);
    }

    double res = (h1/2)*(exp(x0) + exp(xn) + 2*somatorio);
    return res;
}

double FormulaSimpsonRep(int NS, double h2)
{
    double soma = 0;
    double somatorio1 = 0;
    double somatorio2 = 0;

    double x0 = (0*h2);
    x0 = -pow(x0,2);
    double xn = (NS*h2);
    xn = -pow(xn,2);
    double xj;

    for(int j = 1; j <= NS/2; j++)
    {
        xj = ((2*j-1)*h2);
        xj = -pow(xj,2);

        somatorio1 = somatorio1 + exp(xj);
    } 

    for(int j = 1; j < NS/2; j++)
    {
        xj = ((2*j)*h2);
        xj = -pow(xj,2);

        somatorio2 = somatorio2 + exp(xj);
    }

    soma = (h2/3)*(exp(x0) + exp(xn) + 4*somatorio1 + 2*somatorio2);   

    return soma;
}

int main()
{
    //***PARTE 1***//
    double maj1 = majoranteErroT();
    int NT = calcunaN(maj1);

    double maj2 = majoranteErroS();
    int NS = calcunaN(maj2);

    printf("NT = %d\n", NT);
    printf("NS = %d\n", NS);

    //***PARTE 2***//
    double h1 = 1.0/NT;
    double h2;
    if(NS%2 == 0)
        h2 = 1.0/NS;
    else
    {
        NS++;
        h2 = 1.0/NS;
    }

    double res = FormulaTrapezioRep(NT, h1);
    printf("Resposta com formula do Trapezio = %.8lf\n", res);

    double res2 = FormulaSimpsonRep(NS, h2);
    printf("Resposta com formula de Simpson-1/3 = %.8lf\n", res2);
}
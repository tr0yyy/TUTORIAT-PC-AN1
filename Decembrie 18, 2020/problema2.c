#include <stdio.h>
#include <math.h> /// pentru sqrt si abs
                        /// radical si modul

typedef struct 
{
    float re; // partea reala
    float im; // partea imaginara
}complex;


void citire(complex **v, int *n)
{
    scanf("%d", n); /// &(*n) - echivalente
    (*v) = (complex*)malloc((*n) * sizeof(complex));
    for(int i = 0 ; i < (*n) ; i++)
        scanf("%d", &(*v)[i]);
}

float modul (complex x)
{
    float modul = abs(sqrt(x.re*x.re + x.im*x.im));
                    /// modul de radical de x patrat + y patrat
    return modul;
}

int main()
{
    /// problema 2
    complex *v;
    int n;
    citire(&v, &n);
    for(int i = 0 ; i < n ; i++)
        printf("%f %f\n", v[i].re, v[i].im);
    complex maxi;
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if(modul(v[i]) > modul(v[j]))
                maxi = v[i];
            else maxi = v[j];
    printf("%f %f\n", maxi.re, maxi.im);
    printf("\n");
    /// end problema 2
    system("pause");
    return 0;
}
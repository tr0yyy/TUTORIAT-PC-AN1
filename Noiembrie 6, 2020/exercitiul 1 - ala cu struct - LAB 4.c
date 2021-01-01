#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nr_legitimatie;
    char nume[20];
    float nota_mate, nota_info, nota_bac, medie;
    int admis : 2, buget : 2;
}candidati;

int main()
{
    candidati x = {3, "Andrei", 9.4, 10, 8.6, 9.5, 1, 1}; /// asa se atribuie direct membrii structurii
    /// se pot si citi , o sa arat mai jos pt o alta variabila citirea
    candidati y;
    printf("Scrie candidatul y: \n");
    scanf("%d %s %f %f %f %f", &y.nr_legitimatie, y.nume, &y.nota_mate, &y.nota_info, &y.nota_bac, &y.medie);
    /// PENTRU ADMIS SI BUGET, TREBUIE SA SETATI MANUAL, NU SE POATE EFECTUA CITIRE
    y.admis = 0;
    y.buget = 0;
    printf("\nCandidatul x: \n");
    printf("%d %s %f %f %f %f %d %d",x.nr_legitimatie, x.nume, x.nota_mate, x.nota_info, x.nota_bac, x.medie, x.admis, x.buget);
    printf("\nCandidatul y: \n");
    printf("%d %s %f %f %f %f %d %d",y.nr_legitimatie, y.nume, y.nota_mate, y.nota_info, y.nota_bac, y.medie, y.admis, y.buget);
    /// %d - int
    /// %s - char[] SAU char* SAU string
    /// %f - float
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prim(int x)
{
    if(x < 2)
        return 0;
    int i;
    for(i = 2 ; i <= sqrt(x); i++)
        if(x % i == 0)
            return 0; /// 0 - x nu este numar prim
    return 1; /// 1 - x este numar prim
}

int celmaimicdivizopropriu(int x)
{
    int d = 2;
    while (x % d != 0) /// se va opri cand va da de primul numar care e divizibil cu x
        d++;
    if(d == x) /// verificam daca este prim
        return 0;
    return d; /// returnam cel mai mic divizor propriu
}

int main()
{
    int n /* nr linii-coloane*/, nrcad /* nr cadrane*/;
    scanf("%d" , &n);
    int a[101][101];
    if(n % 2 == 1) /// verificam paritatea lui n pt a afla nr de cadrane
        nrcad = n / 2 + 1;
    else nrcad = n / 2;

    /// exemplu cadran
    /* EX:
    n = 5 => 3 rame
    A: ---------------------
       | a   b   c   d   e |
       |   -------------   |
       | f | g   h   i | j |
       |   |   |---|   |   |
       | k | l | m | n | o |
       |   |   |---|   |   |
       | p | q   r   s | t |
       |   -------------   |
       | u   v   w   x   y |
       ---------------------
    n = 4 => 2 rame
    B: ------------------
       | a   b   c   d  |
       |   ---------    |
       | l | m   n | e  |
       |   |       |    |
       | k | p   o | f  |
       |   ---------    |
       | j   i   h   g  |
       ------------------
    */

    a[1][1] = 1;
    int ant = a[1][1];
    for(int i = 1 ; i <= nrcad ; i++) /// parcurgem cadranele
    {
        /// definim anteriorul ca elementul din spate, actualul ca elementul pe care ne aflam

        /// FOR PT PARCURGERE DE LA STANGA LA DREAPTA
        for(int j = i ; j <= n - i + 1 ; j++)  /// practic cursorul nostru este j, pe care-l folosim pt a parcurge in spirala
            {
                if(i == 1 && j == 1)
                    continue; /// sarim peste prima pozitie a cadranului, care este intotdeauna 1
                if(ant == 1) /// nu este prim , dar tot trebuie sa punem ant+1 pt ca asa se face dupa 1
                    a[i][j] = ant+1;
                else
                if(prim(ant) == 1) /// conditia de baza, daca e anteriorul e prim, actualul devine anterior+1;
                    a[i][j] = ant + 1;
                else if(a[i][j-1] == ant){ /// nu este prim, DAAAAR trebuie verificat daca ce e in spate e chiar anteriorul, *vezi exemplu
                                            /// atunci cand se pune 1 2 3 4 2!!!!!!!!
                        a[i][j] = celmaimicdivizopropriu(ant);
                        continue;} /// PENTRU A NU MODIFICA ANTERIORUL, FOLOSIM CONTINUE SA TRECEM LA URMATOAREA ITERATIE
                            else a[i][j] = ant+1; /// altfel, setam anterior+1 , *vezi exemplu atunci cand se puen 1 2 3 4*******!!!!!
                ant = a[i][j]; /// actualizam anteriorul


            }

        /// FOR PT PARCURGERE DE SUS IN JOS
        for(int j = i + 1 ; j <= n - i + 1 ; j++)
        {
            if(prim(ant) == 1) /// conditia de baza, daca e anteriorul e prim, actualul devine anterior+1;
                a[j][n-i+1] = ant + 1;
            else if(a[j-1][n-i+1] == ant){/// nu este prim, DAAAAR trebuie verificat daca ce e in spate e chiar anteriorul, *vezi exemplu
                                            /// atunci cand se pune 1 2 3 4 2!!!!!!!!
                a[j][n-i+1] = celmaimicdivizopropriu(ant);
                continue;}/// PENTRU A NU MODIFICA ANTERIORUL, FOLOSIM CONTINUE SA TRECEM LA URMATOAREA ITERATIE
            else a[j][n-i+1] = ant+1;/// altfel, setam anterior+1 , *vezi exemplu atunci cand se puen 1 2 3 4*******!!!!!
            ant = a[j][n-i+1];/// actualizam anteriorul
        }

        /// FOR PT PARCURGERE DE LA DREAPTA LA STANGA
        for(int j = n - i ; j >= i ; j--){
            if(prim(ant) == 1)/// conditia de baza, daca e anteriorul e prim, actualul devine anterior+1;
                a[n-i+1][j] = ant + 1;
            else if(a[n-i+1][j+1] == ant){/// nu este prim, DAAAAR trebuie verificat daca ce e in spate e chiar anteriorul, *vezi exemplu
                                            /// atunci cand se pune 1 2 3 4 2!!!!!!!!
                a[n-i+1][j] = celmaimicdivizopropriu(ant);
                continue;}/// PENTRU A NU MODIFICA ANTERIORUL, FOLOSIM CONTINUE SA TRECEM LA URMATOAREA ITERATIE
            else a[n-i+1][j] = ant+1;/// altfel, setam anterior+1 , *vezi exemplu atunci cand se puen 1 2 3 4*******!!!!!
            ant = a[n-i+1][j];}/// actualizam anteriorul

        /// FOR PT PARCURGERE DE JOS IN SUS
        for(int j = n - i ; j >= i + 1 ; j--)
        {
                        if(prim(ant) == 1)/// conditia de baza, daca e anteriorul e prim, actualul devine anterior+1;
                a[j][i] = ant + 1;
            else if(a[j+1][i] == ant){/// nu este prim, DAAAAR trebuie verificat daca ce e in spate e chiar anteriorul, *vezi exemplu
                                            /// atunci cand se pune 1 2 3 4 2!!!!!!!!
                a[j][i] = celmaimicdivizopropriu(ant);
                continue;}/// PENTRU A NU MODIFICA ANTERIORUL, FOLOSIM CONTINUE SA TRECEM LA URMATOAREA ITERATIE
            else a[j][i] = ant+1;
            ant = a[j][i];}/// actualizam anteriorul

    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

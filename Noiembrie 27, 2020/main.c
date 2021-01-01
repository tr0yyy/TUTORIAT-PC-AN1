#include <stdio.h>
#include <stdlib.h>
/// Problema din laboratorul 2 unde cere sa transformam un numar din baza 2 in baza 16 fara a il trece prin baza 10
int main()
{
    int i, nr = 0, n;
    char x[20], y;
    printf("Dati numarul de grupuri de biti: ");
    scanf("%d", &n);
    printf("Dati numarul in baza 2: ");
    scanf("%s", x);
    y = 'a';
    printf("%d", y);
    for(i = 0; i < n; i++)
    {
        nr = 0;
        nr = nr + ((x[4*i+3] - 48) * 1);
        nr = nr + ((x[4*i+2] - 48) * 2);
        nr = nr + ((x[4*i+1] - 48) * 4);
        nr = nr + ((x[4*i] - 48) * 8);
        /*if(nr == 10)
            printf("A");
        else
        if(nr == 11)
            printf("B");
        else
        if(nr == 12)
            printf("C");
        else
        if(nr == 13)
            printf("D");
        else
        if(nr == 14)
            printf("E");
        else
        if(nr == 15)
            printf("F");
        else
        printf("%d", nr);*/
        switch(nr)
        {
            case 10:
                printf("A");
                break;

            case 11:
                printf("B");
                break;

            case 12:
                printf("C");
                break;

            case 13:
                printf("D");
                break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
                break;

            default:
                printf("%d", nr);
        }
    }
    return 0;
}

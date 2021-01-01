#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MA(a,b) ((0.8*(a)) + (0.2*(b)))
#define prag 5

/// a

struct candidat
{
    int nr_legitimatie;
    char nume[31];
    float nota_mate;
    float nota_info;
    float nota_bac;
    float medie;
    char admis;
    char buget;
};

/// b - uita-te sus in define, linia 5


/// c - uita-te sus la define, linia 6


/// d

void citire(struct candidat v[101], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %s %f %f %f", &v[i].nr_legitimatie, v[i].nume, &v[i].nota_mate, &v[i].nota_info, &v[i].nota_bac);
        float medie_examen = (v[i].nota_mate + v[i].nota_info) / 2;
        v[i].medie = MA(medie_examen, v[i].nota_bac);
        printf("%f",v[i].medie);
        if(v[i].medie >= prag)
            v[i].admis = 'Y';
        else v[i].admis = 'N';
    }
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if(strcmp(v[i].nume,v[j].nume) > 0)
            {
                struct candidat aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}


/// e

void asignarebuget(struct candidat v[101] , int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if(v[i].medie < v[j].medie) /// descrescatoare dupa medie
            {
                struct candidat aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    int nradmisi = 0;
    for(int i = 0 ; i < n ; i++)
        if(v[i].admis == 'Y')
            nradmisi++;
    int nrbuget = (floor)((3*nradmisi)/4);
    for(int i = 0 ; i < nradmisi ; i++)
        if(i < nrbuget)
            v[i].buget = 'Y';
        else v[i].buget = 'N';
}

/// f

//void meniu_initializare()
// umpleti de printf-uri, spatii, linii noi
// unde scrieti ce inseamna fiecare optiune din meniu

void meniu()
{
    struct candidat v[101];
    int n;
    int opt; /// optiune
    do
    {
        ///meniu_initializare();
        scanf("%d",&opt);
        switch (opt)
        {
        case 1: ///citire n candidati
            scanf("%d",&n);
            citire(v,n);
            asignarebuget(v,n);
            system("pause"); /// Press any key to continue...
            printf("\n\n\n\n");
            break;
        case 2: /// afisam alfabetic
            for(int i = 0 ; i < n - 1 ; i++)
                for(int j = i + 1 ; j < n ; j++)
                    if(strcmp(v[i].nume,v[j].nume) > 0)
                    {
                        struct candidat aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                    }
            for(int i = 0 ; i < n ; i++)
                printf("%s %f",v[i].nume,v[i].medie);
            system("pause");
            printf("\n\n\n\n");
            break;
        case 3:
            for(int i = 0 ; i < n - 1 ; i++)
                for(int j = i + 1 ; j < n ; j++)
                if(v[i].medie < v[j].medie) /// descrescatoare dupa medie
                {
                    struct candidat aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            for(int i = 0 ; i < n ; i++)
                if(v[i].buget == 'Y')
                 printf("%s %f\n",v[i].nume,v[i].medie);
            system("pause");
            printf("\n\n\n\n");
            break;
        case 4:
            for(int i = 0 ; i < n - 1 ; i++)
                for(int j = i + 1 ; j < n ; j++)
                if(v[i].medie < v[j].medie) /// descrescatoare dupa medie
                {
                    struct candidat aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            for(int i = 0 ; i < n ; i++)
                if(v[i].buget == 'N')
                 printf("%s %f\n",v[i].nume,v[i].medie);
            system("pause");
            printf("\n\n\n\n");
            break;
        case 5:
            for(int i = 0 ; i < n - 1 ; i++)
                for(int j = i + 1 ; j < n ; j++)
                if(v[i].medie < v[j].medie) /// descrescatoare dupa medie
                {
                    struct candidat aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            for(int i = 0 ; i < n ; i++)
                if(v[i].admis == 'N')
                 printf("%s %f\n",v[i].nume,v[i].medie);
            system("pause");
            printf("\n\n\n\n");
            break;
        default:
            printf("alegere gresita");
            system("pause");
            break;
        }
    }while(opt != 0);
}

int main()
{
    meniu();
    return 0;
}

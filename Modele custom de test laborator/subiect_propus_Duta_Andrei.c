#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// ex 1
struct elev
{
    char nume[30];
    float notaMate, notaInfo, notaRom, medie;
    char cnp[13];
};
void citire(struct elev v[100], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Nume elev: ");
        scanf("%s",&v[i].nume);
        printf("nota matematica: ");
        scanf("%f",&v[i].notaMate);
        printf("nota informatica: ");
        scanf("%f",&v[i].notaInfo);
        printf("nota Romana: ");
        scanf("%f",&v[i].notaRom);
        printf("CNP: ");
        scanf("%s",&v[i].cnp);
    }

    for(i=0;i<n;i++)
        printf("Numele elevului este: %s\n Acesta a luat urmatoarele note: Matematica: %f\n Informatica: %f\n Romana: %f\n Media Acestuia este: %f\n CNP Elev: %s\n\n", v[i].nume ,v[i].notaMate, v[i].notaInfo,v[i].notaRom, v[i].medie, v[i].cnp);}
/// ex 2
void codificare(struct elev v[100], int n)
{   int i;

    for (i=0;i<n;i++)
    {
        char c1[13];
        strcpy(c1,v[i].cnp+2);
        strncat(c1,v[i].cnp,2);
        strcpy(v[i].cnp,c1);
       /// printf("%s",v[i].cnp);
    }
}
///ex 3
void rotunjire(struct elev v[100], int n)
{   int i,l,k;
    struct elev aux;
    for (i=0;i<n;i++)
    {   int x=v[i].notaMate;
        int y=v[i].notaInfo;
        int z=v[i].notaRom;
        if(v[i].notaMate-x>=0.5)
           v[i].notaMate=x+1;
        else
            v[i].notaMate=x;
        if(v[i].notaInfo-y>=0.5)
           v[i].notaInfo=y+1;
        else
            v[i].notaInfo=y;
        if(v[i].notaRom-z>=0.5)
           v[i].notaRom=z+1;
        else
            v[i].notaRom=z;

        v[i].medie=(v[i].notaMate+v[i].notaInfo+v[i].notaRom)/3;}

        for(l=0;l<n-1;l++)
            for(k=l+1;k<n;k++)
                {
                    if(v[l].medie<v[k].medie)
                    {   aux=v[l];
                        v[l]=v[k];
                        v[k]=aux;}

                if(v[l].medie==v[k].medie)
                if(strcmp(v[l].nume,v[k].nume) > 0)
                        {aux=v[l];
                        v[l]=v[k];
                        v[k]=aux;}
                }


    }

///Ex 4

void fisier (struct elev v[100], int n)
{   int i;
    for(i=0;i<n;i++)
    {
        char c2[13];
        strcpy(c2,v[i].cnp+11);
        strncat(c2,v[i].cnp,11);
        strcpy(v[i].cnp,c2);
        }
    FILE *f= fopen("testare.txt", "w");
    if(f==NULL)
        printf("nu am fisierul");
    for(i=0;i<n;i++)
        fprintf(f,"Numele elevului este: %s   Acesta a luat urmatoarele note: Matematica: %f  Informatica: %f  Romana: %f   Media Acestuia este: %f  CNP Elev: %s \n", v[i].nume ,v[i].notaMate, v[i].notaInfo,v[i].notaRom, v[i].medie, v[i].cnp);

    fclose(f);
}

int main()
{   struct elev v[100];
    int n;
    printf("cati elevi:");
    scanf("%d",&n);
    citire(v,n);
    codificare(v,n);
    rotunjire(v,n);
    fisier(v,n);
    return 0;
}

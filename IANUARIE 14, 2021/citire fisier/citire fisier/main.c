#include <stdio.h>
#include <stdlib.h>

#define fisier "fisier.txt"

/// 1.citire linie cu linie si afisare

void citire()
{
    FILE *f = fopen(fisier, "r");
    if(f == NULL)
        printf("eroare!");
    char s[255];
    while(fgets(s,255,f) != 0)
    {
        printf("%s\n", s);
    }
    fclose(f);
}

/// 2.adaugare in vector de cuvinte, atunci cand exista mai multe semne de punctuatie(vor fi specificate in enunt)
/*void adaugare_cuvinte(char ***v, int *n)
{
    FILE *f = fopen(fisier, "r");
    if(f == NULL)
        printf("eroare!");
    char s[255];
    int i = -1;
    char puncte[] = ",.?!";
    while(fgets(s,255,f) != 0)
    {
        char* p = strtok(s, " ");
        while(p)
        {
            i++;
            if(strchr(puncte,p[strlen(p)-1]))
                p[strlen(p)-1] = NULL;
            (*v) = (struct char)
            strcpy((*v)[i], p);
            p = strtok(NULL, " ");
        }
        j++;
        (*v)[i] = (char*)realloc((j+1) * sizeof(char));
    }
    (*n) = i;
}*/

/*void afisare_cuvinte(char **v, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        int j = 0;
        while(a[i][j])
    }
}*/

int main()
{
    /// 1.
    citire();

    ///2.
    //char** v = (char**)malloc(sizeof(char*));
    //int n;
    //adaugare_cuvinte(&v, &n);
    //n++;



























    /*



    FILE *g = fopen("fisier.out","wb");

    int *v = (int*)malloc(5*sizeof(int));
    for(int i = 0 ; i < 5 ; i++)
    {
        v[i] = i*i*i*i;
    }
    /// v - vectoru unde citiyi
    /// sizeof(int) - marimea tipului de date
    /// 10 - cate elemente vreti sa fie citite din fisierul binar
    /// f - fisierul
    fwrite(v,sizeof(int),5,g);
    fclose(g);
    g = fopen("fisier.out","rb");
    int *vread = (int*)malloc(5*sizeof(int));
    fread(vread,sizeof(int),5,g);
    for(int i = 0 ; i < 5 ; i++)
        printf("%d ", vread[i]);
    /// 10 -cate elemente vreti sa fie afisare in fisierul binar*/
    return 0;
}

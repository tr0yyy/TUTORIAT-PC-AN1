
/*
void citire(int ***a, int *n, int *m)
{
    /// int ***a <-> int *(**a) = pointer spre matricea a
    /// int *n = pointer spre intregul n
    /// int *m = pointer spre intregul m
    /// in orice subprogram de acest tip in care editam parametrii
    /// accesam parametrii cu (*p), unde p = numele parametrului
    scanf("%d %d", n, m); /// &(*n) , &(*m) - echivalente
    (**a) = (int**)malloc((*n) * sizeof(int*));
    for(int i = 0 ; i < (*n) ; i++)
    {
        (*a)[i] = (int*)malloc((*m) * sizeof(int));
        /// alocam linia i ca vector de coloane (m coloane)
        for(int j = 0 ; j < (*m) ; j++)
            scanf("%d", &(*a)[i][j]);
    }   
}

void afisare(int **a, int *n, int *m)
{
    /// aici cum nu editam parametrii, ii folosim normal
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, m;
    int **a;
    citire(&a,&n,&m);
    afisare(a,n,m);
    system("pause");
    return 0;
}*/
/*
#include <stdio.h>

struct nod
{
    int info;
    struct nod* urm;
};

int main()
{
    struct nod *p = (struct nod*)malloc(sizeof(struct nod));
    p -> info = 10;
    printf("%d ",p->info);

    /// adaugare element urmator si afisare folosind nodul p

    struct nod *q = (struct nod*)malloc(sizeof(struct nod));
    q -> info = 20;
    p -> urm = q;
    printf("%d\n", p -> urm -> info);

    system("pause");
    return 0;
}*/

#include <stdio.h>

struct nod
{
    int info;
    struct nod* urm;
};

void adaugare_nod(struct nod **p, int x)
{
    struct nod *q = (struct nod*)malloc(sizeof(struct nod));
    q -> info = x;
    q -> urm = NULL;
    if((*p) == NULL)
        (*p) = q;
    else
    {
        struct nod *u = (struct nod*)malloc(sizeof(struct nod));
        u = (*p);
        while(u -> urm != NULL)
            u = u -> urm;
        u -> urm = q;
        u = q;
    }
}

void afisare_nod(struct nod *p)
{
    struct nod *u = (struct nod*)malloc(sizeof(struct nod));
    u = p;
    while(u != NULL){
        printf("%d ", u->info);
        u = u -> urm;}
}

int main()
{
    int x;
    int n;
    scanf("%d", &n);
    struct nod *p = (struct nod*)malloc(sizeof(struct nod));
    p = NULL;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d",&x);
        adaugare_nod(&p, x);
    }
    afisare_nod(p);
    printf("\n");
    system("pause");
    return 0;
}
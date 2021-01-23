#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produs
{
    float pret;
    char nume[30];
    float discount;
};

struct nod
{
    char info[255];
    struct nod* urm;
};

void citire(struct produs** v, int n)
{
    (*v) = (struct produs*)malloc(n * sizeof(struct produs));
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%f %s %f",&v[i]->pret, (*v)[i].nume, &(*v)[i].discount);
    }
}

void afisare(struct produs* v, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Pret: %f Nume: %s Discount: %f \n",v[i].pret, v[i].nume, v[i].discount);
    }
}

int cmp(struct produs * a, struct produs * b) {
    if(a->pret > b->pret)
        return 1;
    if(a->pret < b->pret)
        return -1;
    if(a->pret == b->pret)
        return strcmp(a->nume, b->nume);
}

void afisare_fisier(struct produs* v, int n)
{
    FILE* f = fopen("fisier.txt", "w+");
    int i;
    for(i = 0; i < n;  i++)
    {
        fprintf(f," Pret final: %f \n Nume: %s \n Discount: %f \n \n",v[i].pret-(v[i].pret*v[i].discount/100), v[i].nume, v[i].discount);
    }
    fclose(f);
}

void adaugare_sortat(struct nod **p , char* x)
{
    struct nod *q = (struct nod*)malloc(sizeof(struct nod));
    strcpy(q -> info,x);
    q -> urm = NULL;
    if((*p) == NULL) /// cazul in care nu exista niciun element
        (*p) = q;
    else if (strcmp(q -> info, (*p) -> info) < 0) /// cazul in care noul nod este mai mic decat primul
    {
        q -> urm = (*p);
        (*p) = q;
    }
    else
    {
        struct nod *u = (struct nod*)malloc(sizeof(struct nod));
        u = (*p);
        int OK = 0;
        while(u -> urm != NULL && OK == 0){
            if(strcmp(u -> urm -> info,q -> info) > 0)
            {
                OK = 1;
                break;
            }
            u = u -> urm;
        }
        if(OK == 1)
            {
                q -> urm = u -> urm;
                u -> urm = q;
            }
        else
            u -> urm = q;
    }
}

int main()
{
    int i, n;
    struct produs* v;
    struct nod* p = (struct nod*) malloc(sizeof(struct nod));
    struct nod* q = (struct nod*) malloc(sizeof(struct nod));
    printf("Dati nr de produse:", &n);
    scanf("%d", &n);
    citire(&v, n);
    qsort(v, n, sizeof(struct produs), cmp);
    afisare(v,n);
    afisare_fisier(v,n);
    p = NULL;
    for(i = 0; i < n; i++)
        adaugare_sortat(&p, v[i].nume);
    printf("Nume: %s \n",p->info);
    q = p;
    while(q->urm != NULL)
    {
        q = q->urm;
        printf("Nume: %s \n",q->info);
    }
    ///alocare compacta
    /*int** m;
    int l, c;
    int i;
    scanf("%d", &l);
    m = (int**) malloc(l*sizeof(int*));
    for(i =0; i < n; i++)
    {
        scanf("%d", &c);
        m[i] = (int*) malloc(c*sizeof(int));
    }*/
    return 0;
}












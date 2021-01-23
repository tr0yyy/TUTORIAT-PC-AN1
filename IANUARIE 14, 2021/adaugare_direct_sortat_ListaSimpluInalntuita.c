#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int info;
    struct nod *urm;
};

void adaugare_sortat(struct nod **p , int x)
{
    struct nod *q = (struct nod*)malloc(sizeof(struct nod));
    q -> info = x;
    q -> urm = NULL;
    if((*p) == NULL) /// cazul in care nu exista niciun element
        (*p) = q;
    else if (q -> info < (*p) -> info) /// cazul in care noul nod este mai mic decat primul
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
            if(u -> urm -> info > q -> info){
                OK = 1;
                break;}
            u = u -> urm;}
        if(OK == 1)
            {
                q -> urm = u -> urm;
                u -> urm = q;
            }
        else
            u -> urm = q;
    }
}

void afisare(struct nod *p)
{
    struct nod *q = (struct nod*)malloc(sizeof(struct nod));
    q = p;
    while(q)
        {
            printf("%d ", q -> info);
            q = q -> urm;
        }
    printf("\n");
}

int main()
{
    struct nod *p = (struct nod*)malloc(sizeof(struct nod));
    p = NULL;
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
        {
            int x;
            scanf("%d",&x);
            adaugare_sortat(&p, x);
        }
    afisare(p);
    return 0;
}
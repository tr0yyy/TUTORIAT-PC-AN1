#include <stdio.h>

void citire(int **v, int *n)
{
    scanf("%d", n); /// &(*n) - echivalente
    (*v) = (int*)malloc((*n) * sizeof(int));
    for(int i = 0 ; i < (*n) ; i++)
        scanf("%d", &(*v)[i]);
}

void sortare(int **v, int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if((*v)[i] > (*v)[j])
                {
                    int aux = (*v)[i];
                    (*v)[i] = (*v)[j];
                    (*v)[j] = aux;
                }
}

/// 11
/// 2 4 8 30 60 80 95 112 135 146 500
/// p                               u
/// 0                               10
///                 p  u              

int cautare_binara(int *v, int n, int k)
{
    int p = 0, u = n - 1, m;
    while(p <= u)
    {
        m = (p + u) / 2;
        if(k == v[m])
            return m;
        else if(k < v[m])
            u = m - 1;
        else p = m + 1;   
    }
    return -1;
}

int main()
{
    int *v;
    int n;
    citire(&v, &n);
    sortare(&v, n);
    printf("\n%d\n", cautare_binara(v,n,112));
    system("pause");
    return 0;
}
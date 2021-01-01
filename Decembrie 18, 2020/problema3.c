#include <stdio.h>

void citire(int **v, int *n)
{
    scanf("%d", n); /// &(*n) - echivalente
    (*v) = (int*)malloc((*n) * sizeof(int));
    for(int i = 0 ; i < (*n) ; i++)
        scanf("%d", &(*v)[i]);
}

int main()
{
    /// problema 3
    int *v;
    int n;
    citire(&v, &n);    
    /// 2 50 4 6 8 50 3 50 7
    /// 1 5 7
    int maxi = v[0];
    for(int i = 1 ; i < n ; i++)
        if(v[i] > maxi)
            maxi = v[i];
    int nr = 0;
    for(int i = 0 ; i < n ; i++)
        if(v[i] == maxi)
            nr++;
    int *a = (int*)malloc(nr * sizeof(int));
    int k = 0;
    for(int i = 0 ; i < n ; i++)
        if(v[i] == maxi)
            {
                a[k] = i;
                k++;
            }
    for(int i = 0 ; i < nr ; i++)
        printf("%d ", a[i]);
    printf("\n");
    free(v);
    free(a);
    system("pause");
    return 0;
}
#include <stdio.h>

int main()
{   
    int a_intreg = 10;
    int *p = &a_intreg;
    printf("%d\n", (*p));
    a_intreg = 20;
    (*p) = 10;
    printf("%d\n", (*p));
    printf("%d\n",p);
    int n;
    scanf("%d", &n);
    int *v = (int*)malloc(n * sizeof(int)); /// 0...n-1
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", v[i]);
    printf("\n");

    /// vrem sa mai adaugam un element
    printf("\n------afisare dupa adaugare-----\n");
    v = (int*)realloc(v,(n+1) * sizeof(int)); /// 0...n
    v[n] = 50; /// v[n] -> ultimul element
    for(int i = 0 ; i <= n ; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);

    /// citire matrice
    printf("\n------afisare dupa adaugare-----\n");

    int m;
    scanf("%d", &m);
    int **matrice = (int**) malloc (m * sizeof(int*));
    for(int i = 0 ; i < m ; i++)
    {
        matrice[i] = (int*) malloc (m * sizeof(int));
        for(int j = 0 ; j < m ; j++)
            scanf("%d", &matrice[i][j]);
    }

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }



    system("pause");
    return 0;
}
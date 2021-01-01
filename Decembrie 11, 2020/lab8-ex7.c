#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*/
    5 6 7 8 9 10 - 6 elemente
    5 5.5 6 6.5 7 7.5 8 8.5 9 9.5 10 - 11 elemente
    n + n - 1 elemente

    5 6 7 8 9 - 5 elemente
    5 5.5 6 6.5 7 7.5 8 8.5 9 - 9 elemente
    /*/

    int n;
    printf("Cate elemente sunt in vector: ");
    scanf("%d", &n);
    float *v = (float*)malloc(n * sizeof(float));
    for(int i = 0 ; i < n ; i++)
        scanf("%f", &v[i]);
    float *vnou = (float*)malloc((n + n - 1) * sizeof(float));
    int i = 0 , j = 0;
    while (i < n && j < n+n-1)
    {
        vnou[j] = v[i];
        i++;
        j += 2;
    }

    /// vnou[] = {5 # 6 # 7 # 8 # 9}
    i = 1;
    while (i < (2*n)-1)
    {
        vnou[i] = (vnou[i-1] + vnou[i+1]) / 2;
        i = i + 2;
    }
    for(int i = 0 ; i < (2*n)-1 ; i++)
        printf("%.2f ", vnou[i]);

    free(v);
    free(vnou);
    
    printf("\n");
    system("pause");
    return 0;
}
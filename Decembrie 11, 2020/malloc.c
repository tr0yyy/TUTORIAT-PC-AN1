#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    /// ALOCARE STATICA
    printf("\n\n---ALOCARE STATICA---\n\n");
    int v[101];
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", v[i]);
    /// --- END ALOCARE STATICA
    
    /// ALOCARE DINAMICA
    printf("\n\n---ALOCARE DINAMICA---\n\n");
    int *s = (int*)malloc(n * sizeof(int)); /// - instructiunea de alocare dinamica
                                            ///   a unui vector de numere intregi de n elemente
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &s[i]);
    
    s = (int*)realloc(s,(n+1)*sizeof(int)); /// realocam memoria pentru a adauga un element in plus
                                            /// in cazul nostru realocam (n+1) elemente.

    s[n] = 30;
    for(int i = 0 ; i <= n ; i++)
        printf("%d ", s[i]);
    free(s); /// dezalocam vectorul pe care am lucrat, deoarece nu-l vom mai folosi pt tot restul programului
    /// --- END ALOCARE DINAMICA

    /// ALOCARE DINAMICA PENTRU STRING
    /// luam in calcul pentru cuvantul "casa" care are 4 caractere + 1 end of line = 5 caractere
    printf("\n\n---ALOCARE DINAMICA STRING---\n\n");
    char *s2 = (char*)malloc(5 * sizeof(char));
    scanf("%s", s2);
    printf("%s", s2);
    free(s2);

    printf("\n");
    system("pause");
    return 0;
}
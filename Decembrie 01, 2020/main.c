#include <stdio.h>

/// 1

typedef struct
{
    char strada[51];
    int numar;
}adresa;

struct comanda
{
    int id_comanda;
    char nume_client[31];
    int id_meniu;
    int pret;
    unsigned int achitat : 1;
    adresa adresa_client;
};

/// 2

void citire(struct comanda v[101] , int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("\nID-ul comenzii: ");
        scanf("%d", &v[i].id_comanda);
        printf("\nNumele clientului: ");
        scanf("%s", v[i].nume_client);
        printf("\nID-ul meniului: ");
        scanf("%d", &v[i].id_meniu);
        printf("\nPretul meniului: ");
        scanf("%d",&v[i].pret);
        printf("A achitat online? (0 - nu ; 1 - da): ");
        ///scanf("%u",&v[i].achitat); - gresit
        int x;
        scanf("%d",&x);
        v[i].achitat = x;
        printf("Strada unde locuieste clientul: ");
        ///scanf("%s",v[i].strada); - gresit
        scanf("%s",v[i].adresa_client.strada);
        printf("Numarul strazii: ");
        scanf("%d",&v[i].adresa_client.numar);
    }
}

void afisare(struct comanda v[101] , int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("\nID-ul comenzii este: %d",v[i].id_comanda);
        printf("\nNumele clientului este: %s",v[i].nume_client);
        printf("\nID-ul meniului: %d", v[i].id_meniu);
        printf("\nPretul meniului: %d", v[i].pret);
        if(v[i].achitat == 1)
            printf("\nComanda achitata deja (online)");
        else printf("\nComanda neachitata (va achita la livrare)");
        printf("\nStrada clientului: %s", v[i].adresa_client.strada);
        printf("\nNumarul strazii: %d", v[i].adresa_client.numar);
        printf("\n");
    }
}

/// 3

void sortare(struct comanda v[101], int n)
{
    int i , j;
    for(i = 0 ; i < n - 1 ; i++)
        for(j = i + 1 ; j < n ; j++)
            if(v[i].pret < v[j].pret)
            {
                ///int a = v[i].pret;
                ///v[i].pret = v[j].pret;
                ///v[j].pret = a;
                /// - gresit , aici schimbi preturile intre comenzi, deci nuuu!!!!
                struct comanda aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void afis_fisier(struct comanda v[101] , int n)
{
    FILE *f = fopen("comenzi.txt","w");
    for(int i = 0 ; i < n ; i++)
        if(v[i].achitat == 1)
        {
            fprintf(f,"%d ",v[i].id_comanda);
            fprintf(f,"%s ",v[i].nume_client);
            fprintf(f,"%d ", v[i].id_meniu);
            fprintf(f,"%d ", v[i].pret);
            fprintf(f,"%s ", v[i].adresa_client.strada);
            fprintf(f,"%d ", v[i].adresa_client.numar);
            fprintf(f,"\n");
        }
    fclose(f);
}

/// 4

int codificare(char nume[31], int id, int pret)
{
    int rezultat1 = id ^ pret; /// ^ - XOR
    int rezultat2 = (int)nume[0];
    rezultat1 = rezultat1 + rezultat2;
    return rezultat1;
}

void citirefisier()
{
    FILE *f = fopen("comenzi.txt","r");
    struct comanda c;
    while(!feof(f))
    {
        ///feof = primul f e de la file , eof = end of file
        /// (f) = fisierul pe care verificati daca s-a ajuns la final
        fscanf(f,"%d", &c.id_comanda);
        fscanf(f,"%s", c.nume_client);
        fscanf(f,"%d", &c.id_meniu);
        fscanf(f,"%d", &c.pret);
        fscanf(f,"%s", c.adresa_client.strada);
        fscanf(f,"%d", &c.adresa_client.numar);
        if(c.pret >= 50)
        {
            printf("%d\n",codificare(c.nume_client, c.id_comanda, c.pret));
        }
    }
}

int main()
{
    struct comanda v[101];
    int n;
    scanf("%d",&n);
    citire(v,n);
    afisare(v,n);
    sortare(v,n);
    afis_fisier(v,n);
    citirefisier();
}
/*

/// citire din fisier cu spatii pe linii
/// si adaugare in vector de cuvinte
/// verificare daca cuvantul este chiar numar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE *f = fopen("spartincuvinte.in","r");
    if(f == NULL)
        printf("poc");
    /// citire normala cu 4 stringuri
    char s[255];
    char a[31][255];
    int n = 0;
    fgets(s,255,f);
    char *p = strtok(s," ");
    while(p)
    {
        strcpy(a[n],p);
        n++;
        p = strtok(NULL," "); /// sare spatiile pana la urmatorul cuvant
    }
    a[n-1][strlen(a[n-1])-1] = '\0'; /// la ultimul cuvant, se pune ca si caracter endline-ul liniei
                                    /// trebuie sters!
    for(int i = 0 ; i < n ; i++)
        {
            int OK = 1; /// presupunem ca este numar
            for(int j = 0 ; j < strlen(a[i]) ; j++) /// strlen(a[i]) - lungimea lui a[i]
                if(a[i][j] < '0' || a[i][j] > '9') /// va trece mai departe daca a[i][j] nu este cifra
                    OK = 0; /// nu este numar
            if(OK)
                printf("%s\n",a[i]);
        }
    system("pause");
}*/

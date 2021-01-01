/// TUTORIAT PROGRAMAREA CALCULATOARELOR - CTI 2020/2021
/// NICOI ALEXANDRU - DUTA ANDREI
/// MODEL TEST LABORATOR 1

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int nr_legitimatie;
    char nume[30];
};

/// problema 1

void citire(struct student v[101], int n)
{
    for(int i = 0 ; i < n  ; i++)
    {
        printf("numar legitimatie: ");
        scanf("%d", &v[i].nr_legitimatie);
        printf("nume: ");
        scanf("%s",v[i].nume);
    }
}

void afisare(struct student v[101], int n)
{
    for(int i = 0 ; i < n ; i++)
        printf("nr legitimatie %d , nume %s\n",v[i].nr_legitimatie,v[i].nume);
}

/// problema 2

void tabloucodif(int tablou[101], struct student v[101], int n, int r, unsigned int cheie)
{
    /// r - rotatie de r biti
    /// cheie - cheie de codificare care e intreg pozitiv (deci unsigned int)
    /// rotire stanga - x = (x << r)|(x >> (8*sizeof(TDI) - r))
    /// rotire dreapta - x = (x >> r)|(x << (8*sizeof(TDI) - r))
    /// unde TDI reprezinta tipul de date al lui x - de regula int sau char
    for(int i = 0 ; i < n ; i++)
    {
        int x = v[i].nr_legitimatie;
        x = (x << r) | (x >> (8 * sizeof(int) - r));
        tablou[i] = x ^ cheie;
        printf("%d ", tablou[i]);
    }
}

/*//// problema 3 - fisier binar!!
void scrierebinary(int tablou[101] , int n)
{
    FILE *f = fopen("fisier.bin","wb");
    for(int i = 0 ; i < n ; i++) {
        int x = tablou[i];
        fwrite(&x, sizeof(int), 1, f);
        fprintf(f, "\n");
    }
    fclose(f);
}/*/

void numarbinar(int x, FILE *f)
{
    if(x != 0)
    {
        numarbinar(x/2,f);
        int rest = x % 2;
        fprintf(f,"%d",rest);
    }
}

void scrierenumarbinar(FILE *f, int tablou[101] , int n) {
    for (int i = 0; i < n; i++) {
        int x = tablou[i];
        numarbinar(x, f);
        fprintf(f, "\n");
    }
    fclose(f);
}

/// problema 4
/*
 *  CITIRE DIN FISIER BINAR
 * int citirebinary(int tablou[101], int n, int linie, int r, unsigned int cheie)
{
    FILE *f = fopen("fisier.bin","rb");
    if(linie > n)
    {
        printf("EROARE! Linia ceruta nu exista!");
        return -1; /// iesim din functie cu -1
    }/// nu mai punem else deoarece nu are sens, caci daca ajunge sa intre in if, va iesi din program
    /// din cauza return-ului
    for(int i = 0 ; i < linie ; i++) /// parcurgem fisierul pana la linia dorita
    {
        int x;
        fread(&x,sizeof(int),1,f);
        int c = fgetc(f); /// sa sar peste spatiu (\n) lasat in fisier
        if(i + 1 == linie) /// conditia de linie ceruta
        {
            x = x ^ cheie;
            x = (x >> r)|(x << (8*sizeof(int) - r));
            fclose(f); /// inchidem fisierul deoarece vom iesi din program
            return x; /// returnam elementul decodificat
        }
    }

}*/

int binarytodecimal(int x)
{
     int s = 0 , exp = 1;
     while(x)
     {
         int bit = x % 10;
         s = s + bit * exp;
         exp = exp * 2;
         x = x / 10;
     }
     return s;
}

int citirenumarbinar(FILE *f , int linie , int n , int r, unsigned int cheie)
{
    if(linie > n)
    {
        printf("EROARE! Linia ceruta nu exista!");
        return -1; /// iesim din functie cu -1
    }/// nu mai punem else deoarece nu are sens, caci daca ajunge sa intre in if, va iesi din program
    /// din cauza return-ului
    for(int i = 0 ; i < linie ; i++) /// parcurgem fisierul pana la linia dorita
    {
        int x;
        char s[11];
        fscanf(f,"%s",s); /// citim numarul in binar ca sir de caractere
        int c = fgetc(f); /// sa sar peste spatiu (\n) lasat in fisier
        if(i + 1 == linie) /// conditia de linie ceruta
        {
            x = atoi(s); /// transformam sirul de caractere in numar :)
            x = binarytodecimal(x); /// convertim inapoi in baza 10
            x = x ^ cheie;
            x = (x >> r)|(x << (8*sizeof(int) - r));
            fclose(f); /// inchidem fisierul deoarece vom iesi din program
            return x; /// returnam elementul decodificat
        }
    }

}

int main() {
    int n;
    printf("cati studenti: ");
    scanf("%d",&n);
    /// alocare dinamica - optionala pt acest test
    //struct student *v = (struct student *)malloc(n * sizeof(struct student));
    /// daca mergeti pe alocare dinamica , folositi codul model_test1_alocare_dinamica
    struct student v[101];

    citire(v,n);
    afisare(v,n);

    /// problema 2
    int tablou[101]; /// aici voi pune numerele de legitimatie codificate
    int r;
    unsigned int cheie;
    printf("Numarul de biti pentru rotatie si cheia de codificare: ");
    scanf("%d %u",&r,&cheie);
    tabloucodif(tablou,v,n,r,cheie);
    /*/for(int i = 0 ; i < n;  i++)
        printf("%d",tablou[i]); pentru verificare /*/

    /// problema 3
    FILE *f = fopen("fisier.out", "w");
    scrierenumarbinar(f,tablou,n);

    /// problema 4
    f = fopen("fisier.out", "r");
    printf("%d",citirenumarbinar(f,2,n,r,cheie));
    return 0;
}

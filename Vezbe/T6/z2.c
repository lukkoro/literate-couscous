#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30
#define MAXIME 30+1
#define MAXADRESA 40+1

typedef struct licnost{
    char ime[MAXIME];
    char adresa[MAXADRESA];
    int dan;
    int mesec;
    int godina;
} LICNOST;

void ucitaj(LICNOST *, int *);
void bik(LICNOST *, int);

int main() {
    LICNOST osoba[MAX_SIZE];
    int n;
    ucitaj(osoba, &n);
    bik(osoba, n);
}

void ucitaj(LICNOST *osoba, int *n) {
    printf("Unesite broj osoba: ");
    scanf("%d", n);

    for(int i = 0; i < *n; i++) {
        printf("%d. osoba: \n", i+1);
        printf("\tIme: ");
        scanf(" %[^\t\n]s", osoba[i].ime);
        printf("\tAdresa: ");
        scanf(" %[^\t\n]s", osoba[i].adresa);
        printf("\tDan rodjenja: ");
        scanf("%d", &osoba[i].dan);
        printf("\tMesec rodjenja: ");
        scanf("%d", &osoba[i].mesec);
        printf("\tGodina rodjenja: ");
        scanf("%d", &osoba[i].godina);
    }
}

void bik(LICNOST *osoba, int n) {
    int i;
    printf("Osobe koje su u horoskopu bik: \n");
    for(i = 0; i < n; i++) {
        if((osoba[i].mesec == 4 && osoba[i].dan >= 20) || (osoba[i].mesec == 5 && osoba[i].dan <= 20)) {
            printf("\tIme: %s   Adresa: %s   Datum rodjenja: %d.%d.%d\n", osoba[i].ime, osoba[i].adresa, osoba[i].dan, osoba[i].mesec, osoba[i].godina);
        } 
    }
}
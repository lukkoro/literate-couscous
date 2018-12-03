#include <stdio.h>
#include <string.h>
#define MAXEKIPA 20
#define MAXIME 30+1

typedef struct ekipa {
    char naziv[MAXIME];
    unsigned bodovi;
    int razlika;
} EKIPA;

void sort(EKIPA *, int);
void ispis(EKIPA *, int);
void ucitaj(EKIPA *, int *);
void razmeni(EKIPA *, EKIPA *);

int main() {
    int n;
    EKIPA tabela[MAXEKIPA];
    ucitaj(tabela, &n);
    sort(tabela, n);
    ispis(tabela, n);

    return 0;
}

void ucitaj(EKIPA *tabela, int *n) {
    printf("Unesite broj ekipa: ");
    scanf("%d", n);

    for(int i = 0; i < *n; i++) {
        getchar();
        printf("%d. ekipa: ", i+1);
        fgets(tabela[i].naziv, MAXIME, stdin);
        strtok(tabela[i].naziv, "\n");
        printf("\tBroj bodova: ");
        scanf("%u", &tabela[i].bodovi);
        printf("\tGol razlika: ");
        scanf("%d", &tabela[i].razlika);
    }
}

void sort(EKIPA *tabela, int n) {
    int i, j, trans;
    char tr;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if((tabela[j].bodovi > tabela[i].bodovi) || (tabela[j].bodovi == tabela[i].bodovi && tabela[j].razlika > tabela[i].razlika)) {
                razmeni(&tabela[i], &tabela[j]);
            }

        }
    }
}

void razmeni(EKIPA *a, EKIPA *b) {
    EKIPA pom;
    pom = *a;
    *a = *b;
    *b = pom;
}

void ispis(EKIPA *tabela, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d. ekipa: ", i+1);
        printf("%s  %u  %d\n", tabela[i].naziv, tabela[i].bodovi, tabela[i].razlika);
    }
}
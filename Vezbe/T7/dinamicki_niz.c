#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dinamicki_niz_st {
    int *pniz;
    int kapacitet;
    int puno;
} DNIZ;

void inic_niz(DNIZ *);
void dodaj_rand(DNIZ *);
void dodaj(DNIZ *, int);
void skloni(DNIZ *);
void pogledaj(DNIZ *);
void povecaj_niz(DNIZ *);
void ispisi_niz(DNIZ);
void obrisi_niz(DNIZ *);
void obrisi_elemente(DNIZ *, int);
int velicina_niza(DNIZ);
DNIZ prosti_brojevi(DNIZ d);


int main() {
    DNIZ d;
    DNIZ prosti;

    inic_niz(&d);
    inic_niz(&prosti);

    srand(time(NULL));
    int i;
    for(i = 0; i < 20; i++) {
        dodaj_rand(&d);
        ispisi_niz(d);
    }

    int vrednost;
    printf("Vrednost koju zelite da izbrisete: ");
    scanf("%d", &vrednost);
    obrisi_elemente(&d, vrednost);
    ispisi_niz(d);

    prosti = prosti_brojevi(d);
    ispisi_niz(prosti);

    obrisi_niz(&d);
    ispisi_niz(d);

    return 0;
}

void inic_niz(DNIZ *d) {
    d->pniz = NULL;
    d->kapacitet = 0;
    d->puno = 0;
}

void dodaj_rand(DNIZ *d) {
    int vred;
    if(d->puno == d->kapacitet) {
        povecaj_niz(d);
    }

    vred = rand() % 20;

    d->pniz[d->puno] = vred;
    d->puno++;
}

void dodaj(DNIZ *d, int vred) {
    if(d->puno == d->kapacitet) {
        povecaj_niz(d);
    }

    d->pniz[d->puno] = vred;
    d->puno++;
}

void povecaj_niz(DNIZ *d) {
    if(d->kapacitet == 0) {
        d->kapacitet = 1;
    }
    else {
        d->kapacitet *= 2;
    }

    d->pniz = realloc(d->pniz, d->kapacitet * sizeof(int));
}

void ispisi_niz(DNIZ d) {
    int i;
    printf("[");
    for(i = 0; i < d.puno; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", d.pniz[i]);
    }
    printf("]\n");
    printf("Velicina niza: %d\n\n", velicina_niza(d));
}

void obrisi_niz(DNIZ *d) {
    free(d->pniz);
    inic_niz(d);
}

int velicina_niza(DNIZ d) {
    return d.kapacitet;
}

void obrisi_elemente(DNIZ *d, int vred) {
    int i;
    DNIZ bez;
    inic_niz(&bez);
    for(i = 0; i < d->puno; i++) {
        if(d->pniz[i] != vred) {
            dodaj(&bez, d->pniz[i]);
        }
    }

    obrisi_niz(d);

    for(i = 0; i < bez.puno; i++) {
        dodaj(d, bez.pniz[i]);
    }
}

DNIZ prosti_brojevi(DNIZ d) {
    DNIZ prosti;
    inic_niz(&prosti);
    int i, j, jeProst;
    for(i = 0; i < d.puno; i++) {
        jeProst = 1;
        for(j = 2; pow(j,2) <= d.pniz[i]; j++) {
            if(d.pniz[i] % j == 0) {
                jeProst = 0;
            }
        }
        if(jeProst && d.pniz[i] != 0) {
            dodaj(&prosti, d.pniz[i]);
        }
    }

    return prosti;
}
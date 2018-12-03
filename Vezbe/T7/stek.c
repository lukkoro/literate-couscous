#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dinamicki_niz_st {
    int *pniz;
    int kapacitet;
    int puno;
} DNIZ;

void inic_niz(DNIZ *);
void dodaj(DNIZ *);
void skloni(DNIZ *);
void pogledaj(DNIZ *);
void povecaj_niz(DNIZ *);
void ispisi_niz(DNIZ);
void obrisi_niz(DNIZ *);
void obrisi_element(DNIZ *);
int velicina_niza(DNIZ);


int main() {
    DNIZ d;

    inic_niz(&d);

    srand(time(NULL));
    int i;
    for(i = 0; i < 20; i++) {
        dodaj(&d);
        ispisi_niz(d);
    }

    for(i = 0; i < 20; i++) {
        skloni(&d);
        ispisi_niz(d);
    }

    obrisi_niz(&d);
    ispisi_niz(d);

    return 0;
}

void inic_niz(DNIZ *d) {
    d->pniz = NULL;
    d->kapacitet = 0;
    d->puno = 0;
}

void dodaj(DNIZ *d) {
    int vred;
    if(d->puno == d->kapacitet) {
        povecaj_niz(d);
    }

    vred = rand() % 20;

    d->pniz[d->puno] = vred;
    d->puno++;
    
    printf("PUSH : %d\n", vred);
}

void povecaj_niz(DNIZ *d) {
    if(d->kapacitet == 0) {
        d->kapacitet = 1;
    }
    else {
        d->kapacitet++;
    }

    d->pniz = realloc(d->pniz, d->kapacitet * sizeof(int));
}

void ispisi_niz(DNIZ d) {
    int i;
    printf("[");
    for(i = 0; i < d.puno; i++) {
        printf("%d ", d.pniz[i]);
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

void skloni(DNIZ *d) {
    pogledaj(d);
    obrisi_element(d);
    d->pniz = realloc(d->pniz, d->puno * sizeof(int));
    d->kapacitet = d->puno;
}

void obrisi_element(DNIZ *d) {
    d->puno--;
}

void pogledaj(DNIZ *d) {
    printf("POP : %d\n", d->pniz[d->puno - 1]);
}
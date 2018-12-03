#include <stdio.h>
#include <stdlib.h>

void kodiraj(char *ul_dat, char *izl_dat);
void dekodiraj(char *ul_dat);

int main(int argNum, char *arg[]) {
    if(argNum != 3) {
        exit(-1);
    }

    char *ulazna = arg[1];
    char *izlazna = arg[2];
    kodiraj(ulazna, izlazna);
    dekodiraj(izlazna);
}

void kodiraj(char *ul_dat, char *izl_dat) {
    FILE *ulazna = fopen(ul_dat, "r");
    FILE *izlazna = fopen(izl_dat, "w");
    if(ulazna == NULL) {
        printf("%s ne moze da se otvori ili ne postoji.", ul_dat);
        exit(-1);
    }
    else if(izlazna == NULL) {
        printf("%s ne moze da se otvori za pisanje.", izl_dat);
        exit(-1);
    }

    char ch;
    while((ch = getc(ulazna)) != EOF) {
        if(ch >= 'A' && ch < 'Z' || ch >= 'a' && ch < 'z') {
            fprintf(izlazna, "%c", ch+1);
        }
        else if(ch == 'Z' || ch == 'z') {
            fprintf(izlazna, "%c", ch-24);
        }
        else {
            fprintf(izlazna, "%c", ch);
        }
    }
    fseek(ulazna,0,0);
}

void dekodiraj(char *ul_dat) {
    FILE *ulazna = fopen(ul_dat, "r");
    FILE *izlazna = fopen("izlazna_dekodirana.txt", "w");
    if(ulazna == NULL) {
        printf("%s ne moze da se otvori ili ne postoji.", ul_dat);
        exit(-1);
    }
    else if(izlazna == NULL) {
        printf("izlazna_dekodirana.txt ne moze da se otvori za pisanje.");
        exit(-1);
    }

    char ch;
    while((ch = getc(ulazna)) != EOF) {
        if(ch > 'A' && ch <= 'Z' || ch > 'a' && ch <= 'z') {
            fprintf(izlazna, "%c", ch-1);
        }
        else if(ch == 'a' || ch == 'A') {
            fprintf(izlazna, "%c", ch+24);
        }
        else {
            fprintf(izlazna, "%c", ch);
        }
    }
    fseek(ulazna,0,0);
}
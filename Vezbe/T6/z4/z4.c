#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100+1

int main(int arg, char *args[]) {
    
    if(arg < 3) {
        printf("Nedovoljan broj argumenata. \nPravilno koriscenje: ./z4 ulazna_datoteka.txt izlazna_datoteka.txt");
        exit(EXIT_FAILURE);
    }
    else if(arg > 3) {
        printf("Previse argumenata. \nPravilno koriscenje: ./z4 ulazna_datoteka.txt izlazna_datoteka.txt");
        exit(EXIT_FAILURE);
    }

    char *ime_ulazne = args[1];
    char *ime_izlazne = args[2];
    FILE *ulaz, *izlaz;
    ulaz = fopen(ime_ulazne, "r");
    izlaz = fopen(ime_izlazne, "w");

    if(ulaz == NULL) {
        printf("Ulazna datoteka ne moze da se otvori ili ne postoji.\n");
        exit(EXIT_FAILURE);
    }

    if(izlaz == NULL) {
        printf("Greska prilikom otvaranja datoteke %s za pisanje.", ime_izlazne);
    }

    char ch;
    int w = 0;
    char str[MAX_SIZE], strMax[MAX_SIZE];
    int strLength = 0, strMaxLength = 0;

    while((ch = getc(ulaz)) != EOF) {
        if(ch >= 'A' && ch<='Z' || ch >= 'a' && ch <= 'z') {
            str[strLength++] = ch;    
        }
        else if(strLength) {
            w++;
            str[strLength+1] = '\0';
            if(strLength > strMaxLength) {
                strcpy(strMax, str);
                strMaxLength = strLength;
            }
            strLength = 0;
        }
    } 
    fprintf(izlaz,"U fajlu %s ima %d reci. Najduza pronadjena rec je %s.", ime_ulazne, w, strMax);
    fclose(ulaz);

    return 0;
}
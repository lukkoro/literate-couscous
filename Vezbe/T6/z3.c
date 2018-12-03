#include <stdio.h>
#define MAXMARKA 20+1
#define MAX_SIZE 30

typedef struct automobil{
    char marka[MAXMARKA];
    int kubikaza;
    int godiste;
} AUTO;

void ucitaj(AUTO *, int *);

int main() {
    AUTO a[MAX_SIZE];
    int n, i;
    ucitaj(a, &n);

    int zeljena_kubik;
    printf("Unesite zeljenu kubikazu: ");
    scanf("%d", &zeljena_kubik);
    
    int maxYr = a[0].godiste;
    int maxIdx = 0;
    for(i = 0; i < n; i++) {
        if(a[i].godiste > maxYr && a[i].kubikaza <= zeljena_kubik) {
            maxIdx = i;
        }
    }

    printf("Najnoviji sa ne vecom kubikazom: \n");
        printf("\tMarka: %s", a[maxIdx].marka);
        printf("\tKubikaza: %d", a[maxIdx].kubikaza);
        printf("\tGodina proizvodnje: %d\n", a[maxIdx].godiste);
}

void ucitaj(AUTO *a, int *n) {
    printf("Unesite broj auta: ");
    scanf("%d", n);
    printf("MARKA   KUBIKAZA    GODISTE\n");
    for(int i = 0; i < *n; i++) {
        scanf("%s %d %d", a[i].marka, &a[i].kubikaza, &a[i].godiste);
        /*printf("%d. automobil: \n", i+1);
        getchar();
        printf("\tMarka: ");
        scanf("%[^\t\n]s", a[i].marka);
        printf("\tKubikaza: ");
        scanf("%d", &a[i].kubikaza);
        printf("\tGodina proizvodnje: ");
        scanf("%d", &a[i].godiste);*/
    }
}
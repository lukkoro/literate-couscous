#include <stdio.h>
#include <math.h>
#define MAX_SIZE 30
#define COMPLEX 2

typedef struct tacka {
    float x;
    float y;
    float z;
} TACKA;

typedef struct kompleksni_broj{
    float Re;
    float Im;
} KOMPLEKS;

void najbliza_tacka(TACKA *, int);
void najdalja_tacka(TACKA *, int);
void kompleksni(KOMPLEKS *);

int main() {
    TACKA t[MAX_SIZE];
    KOMPLEKS c[COMPLEX];
    int n;
    do {
        printf("Unesite broj tacaka: ");
        scanf("%d", &n);
    } while(n < 0 || n > MAX_SIZE);

    for(int i = 0; i < n; i++) {
        printf("x%d = ", i+1);
        scanf("%f", &t[i].x);
        printf("y%d = ", i+1);
        scanf("%f", &t[i].y);
        printf("z%d = ", i+1);
        scanf("%f", &t[i].z);
    }

    for(int i = 0; i < n; i++) {
        printf("x%d = %f, y%d = %f, z%d = %f\n", i+1, t[i].x, i+1, t[i].y, i+1, t[i].z);
    }

    najbliza_tacka(t, n);
    najdalja_tacka(t, n);

    n = COMPLEX;
    for(int i = 0; i < n; i++) {
        printf("Realni deo %d. kompleksnog broja: ", i+1);
        scanf("%f", &c[i].Re);
        printf("Imaginarni deo %d. kompleksnog broja: ", i+1);
        scanf("%f", &c[i].Im);
    }

    kompleksni(c);
}

void najbliza_tacka(TACKA *t, int n) {
    float d;
    int minIdx;
    d = pow(t[0].x, 2) + pow(t[0].y, 2) + pow(t[0].z, 2);
    for(int i = 1; i < n; i++) {
        if(d > pow(t[i].x, 2) + pow(t[i].y, 2) + pow(t[i].z, 2)) {
            d = pow(t[i].x, 2) + pow(t[i].y, 2) + pow(t[i].z, 2);
            minIdx = i;
        }
    }

    printf("Najbliza tacka je:\tx%d = %f\ty%d = %f\tz%d = %f\n", minIdx+1, t[minIdx].x, minIdx+1, t[minIdx].y, minIdx+1, t[minIdx].z);
}

void najdalja_tacka(TACKA *t, int n) {
    float d;
    int maxIdx;
    d = pow(t[0].x, 2) + pow(t[0].y, 2) + pow(t[0].z, 2);
    for(int i = 1; i < n; i++) {
        if(d < pow(t[i].x, 2) + pow(t[i].y, 2) + pow(t[i].z, 2)) {
            d = pow(t[i].x, 2) + pow(t[i].y, 2) + pow(t[i].z, 2);
            maxIdx = i;
        }
    }

    printf("Najudaljenija tacka je:\tx%d = %f\ty%d = %f\tz%d = %f\n", maxIdx+1, t[maxIdx].x, maxIdx+1, t[maxIdx].y, maxIdx+1, t[maxIdx].z);
}

void kompleksni(KOMPLEKS *c) {
    float Re, Im;
    Re = c[0].Re + c[1].Re;
    Im = c[0].Im + c[1].Im;
    if(Im < 0) {
        printf("c = %.2f %.2f*i\n", Re, Im);
    }
    else {
        printf("c = %.2f + %.2f*i\n", Re, Im);
    }
    Re = c[0].Re - c[1].Re;
    Im = c[0].Im - c[1].Im;
    if(Im < 0) {
        printf("c = %.2f %.2f*i\n", Re, Im);
    }
    else {
        printf("c = %.2f + %.2f*i\n", Re, Im);
    }
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30+1

int myatof(char *string);

int main() {
    char string[MAX_SIZE];
    float f;
    fgets(string, MAX_SIZE-1, stdin);

    f = myatof(string);
    printf("%f", f);

}

int myatof(char *string) {
    
    int decimal_point, dec_occur = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if (string[i]=='.') {
            decimal_point = i;
            dec_occur++;
        }
        if (dec_occur > 1) {
            printf("Error: String has more than one decimal point.");
            exit(-1);
        }
    }

    float f = 0;
    int n;
    for(int i = 0; i < decimal_point; i++) {
        n = string[i]*1;
        for(int j = 0; j <= decimal_point; j++) {
            n *= 10;
        }
        f += n;
    }

    return f;
}
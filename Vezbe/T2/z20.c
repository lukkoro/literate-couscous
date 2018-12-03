#include <stdio.h>
#include <math.h>
#define MAX 20

int main () {
	static int srn[MAX];
	int i, n, najblizi, srednja, ostatak1, ostatak2=1, suma=0;
	
	do {
		printf("Unesite broj clanova niza: ");
		scanf("%d", &n);
	} while (n<=0 || n>MAX);
	
	for (i=0;i<n;i++) {
		printf("srn[%d] = ", i);
		scanf("%d", &srn[i]);
		suma=suma+srn[i];
	}
	
	srednja=suma/i;
	
	for (i=0;i<n;i++) {
		ostatak1=abs(srednja-srn[i]);
		if (ostatak1<=ostatak2) {
			najblizi=srn[i];
		}
	}
	
	return 0;
	
}

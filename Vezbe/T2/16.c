#include <stdio.h>
#define MAX 20
int main () {

	int i, niz[MAX], max=0, n;
	
	do {
		printf("Unesite broj elemenata u nizu: ");
		scanf("%d", &n);
	} while (n>MAX || n<=0);
	
	for (i=0;i<n;i++){
		printf("niz[%d] = ", i);
		scanf("%d", &niz[i]);
		
		if (niz[i]>max){
			max=niz[i];
		}
	}
	
	printf("Maksimalna vrednost je %d", max);
	
	return 0;
}

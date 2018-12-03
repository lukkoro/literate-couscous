#include <stdio.h>
#define MAX 30

int main () {
	int i, niz[MAX], br, brp=0, n;
	
	do {
		printf("Unesite broj elemenata u nizu: ");
		scanf("%d", &n);
	} while (n>MAX || n<=0);
	
	for (i=0;i<n;i++){
		printf("niz[%d] = ", i);
		scanf("%d", &niz[i]);
	}
	
	printf("Unesite broj koji zelite da proverite: ");
	scanf("%d", &br);
	
	for (i=0;i<n;i++) {
		if (niz[i]==br) {
			brp=brp+1;
		}
	}
	
	printf("Broj %d se pojavljuje %d puta u ovom nizu.", br, brp);
	
	return 0;
}

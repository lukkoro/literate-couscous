#include <stdio.h>

int main () {
	int i, j, n, k, mno=1, suma=0;
	
	printf("S=1*2+2*3*4+3*4*5*6...(n+0)*(n+1)*(n+2)...(n+n)\n");
	
	do {
		printf("Unesite n: ");
		scanf("%d", &n);
	} while (n<1);
	
	
	for (i=1;i<=n;i++) {
	
		k=2*i;
		for (j=0;j<=k;j++){
			mno=mno*(i+j);
		}
		suma=suma+mno;
	}
	
	printf("%d\n", suma);
	
	return 0;
}

#include <stdio.h>
#define MAX 25

int main () {
	static int X[MAX], A[MAX], B[MAX];
	int n, i, brojacn=0, brojacp=0;
	
	
	do {
		printf("Unesite broj elemenata u nizu: ");
		scanf("%d", &n);
	} while (n>MAX || n<=0);
	
	for (i=0;i<n;i++){
		printf("X[%d] = ", i);
		scanf("%d", &X[i]);
	}
	
	for (i=0;i<n;i++) {
		if (X[i]%2==0){
			A[brojacp]=X[i];
			brojacp++;
		}
		else {
			B[brojacn]=X[i];
			brojacn++;
		}
	}
	
	for (i=0;i<n;i++) {
		printf("X[%d]=%d, A[%d]=%d, B[%d]=%d\n", i, X[i], i, A[i], i, B[i]);
	}
	
	return 0;
}

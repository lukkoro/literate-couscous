#include <stdio.h>
#define MAX 20

int main () {
	static double A[MAX][MAX],B[MAX][MAX];
	int i, j, n, trans;
	
	do {
		printf("Unesite velicinu celobrojne kvadratne matrice: ");
		scanf("%d", &n);
	} while (n<=0 || n>MAX);
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%lf", &A[i][j]);
		}
	}
	
	printf("\n\nOriginalna matrica:");
	for (i=0;i<n;i++) {
		printf("\n");
		for (j=0;j<n;j++) {
			printf(" %.2lf", A[i][j]);
		}
	}
	
	for (i=0;i<n;i++) {
		
		for (j=0;j<n;j++) {
			B[i][j]=A[j][i];
		}
	}
	
	printf("\n\nTransponovana matrica:");
	for (i=0;i<n;i++) {
		printf("\n");
		for (j=0;j<n;j++) {
			printf(" %.2lf", B[i][j]);
		}
	}
	
	printf("\n");
	
	return 0;
}


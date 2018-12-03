#include <stdio.h>
#define MAX 20

int main () {
	static int A[MAX][MAX];
	int i, j, n, suma=0;
	
	do {
		printf("Unesite velicinu celobrojnih kvadratnih matrica: ");
		scanf("%d", &n);
	} while (n<=0 || n>MAX);
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	
	for (i=n-1;i>0;i--) {
		for(j=n-i;j<n;j++) {
			suma=suma+A[i][j];
			printf("%d\n", suma);
		}
	}
	
	printf("%d\n", suma);
	
	return 0;
}

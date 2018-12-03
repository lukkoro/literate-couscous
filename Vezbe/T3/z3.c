#include <stdio.h>
#define MAX 20

int main () {
	static int A[MAX][MAX];
	int i, j, n, max=0, maxbr, min, minbr, trans;
	
	do {
		printf("Unesite velicinu celobrojne kvadratne matrice: ");
		scanf("%d", &n);
	} while (n<=0 || n>MAX);
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
			if (A[i][j]>max) {
				max=i;
				maxbr=A[i][j];
			}
		}
	}
	
	for (i=0;i<n;i++) {
		printf("\n");
		for (j=0;j<n;j++) {
			printf(" %d", A[i][j]);
		}
	}
	printf("\n\n");
	
	min=maxbr;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (A[i][j]<min) {
				min=i;
				minbr=A[i][j];
			}
		}
	}
	
	printf("Najveci element matrice nalazi se u %d vrsti, a najmanji u %d vrsti.\n", max, min);
	
	for (j=0;j<n;j++) {
		trans = A[max][j];
		A[max][j] = A[min][j];
		A[min][j]=trans;
	}
	
	for (i=0;i<n;i++) {
		printf("\n");
		for (j=0;j<n;j++) {
			printf(" %d", A[i][j]);
		}
	}
	printf("\n");
	
	return 0;
}

#include <stdio.h>
#define MAX 80

int main () {
	static char C[MAX], A[MAX];
	int i, j, n;
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while (n<=0 || n>MAX);
	
	j=0;
	for (i=0;i<n;i++) {
		printf("C[%d] = ", i);
		scanf(" %c", &C[i]);
		if (C[i]>64 && C[i]<91 || C[i]>97 && C[i]<122) {
			A[j]=C[i];
			j++;
		}
	}
	
	printf("\nKarakteri u nizu su:\n\n");
	for (i=0;i<j;i++) {
		printf("A[%d] = %c\n", i, A[i]);
	}
	
	return 0;
}

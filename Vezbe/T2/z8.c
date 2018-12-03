#include <stdio.h>

int main () {
	int fakt,i,n;

	do {
		printf("Unesite prirodan broj: ");
		scanf("%d",&n);
	}
	while (n<0);

	fakt=1;
	for (i=1;i<=n;i++){
		fakt=fakt*i;
	}
	printf("Faktorijel broja %d je: %d\n",n,fakt);

	return 0;
}

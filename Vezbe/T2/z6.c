#include <stdio.h>

int main () {
	int i,n,sum;

	printf("Unesite broj: ");
	scanf("%d",&n);

	sum=0;
	for(i=0;i<=n;i++){
		sum=sum+i;
	}
	
	printf("Zbir prvih %d prirodnih brojeva je %d\n",n,sum);
	return 0;
}

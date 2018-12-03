#include <stdio.h>

int main () {
	int n,i,pro=0;

	do{
		printf("Unesite pozitivan ceo broj: ");
		scanf("%d", &n);
	}
	while (n<1);
	
	for(i=2;i<=n/2;++i){
		if(n%i==0) {
			pro=1;
			break;
		}
	}
	
	if (pro==1)
		printf("Broj %d nije prost.\n",n);
	else
		printf("Broj %d je prost.\n",n);
		
	return 0;
}


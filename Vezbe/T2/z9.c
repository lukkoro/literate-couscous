#include <stdio.h>

int main () {
	int n,q,i,ostatak;

	do {
	printf("Unesite broj i kolicnik: ");
	scanf("%d %d", &n,&q);
	}
	while(n<0 || q<0);

	i=2;
	while(i<=n){
		ostatak=i%q;
		if (ostatak==0) {
			printf("%d\n",i);
		}
		i++;
	}

	return 0;	
}

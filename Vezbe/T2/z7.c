#include <stdio.h>

int main() {
	int a,b,mno,i;

	printf("Unesite dva broja: ");
	scanf("%d %d", &a,&b);

	i=0;
	mno=0;
	for (i=1;i<=b;i++){
		mno=mno+a;
	}
	printf("a*b=%d\n",mno);
	
	if (a>0 && b>0) {

		for (i=0;a>=b;i++) {
			a=a-b;
		}
		printf("a/b=%d\n",i);
	}

	else if (a==0) {
		i=0;
		printf("a/b=%d\n",i);
	}

	else {
		printf("Deljenje nulom je nemoguce.\n");
	}
	
	return 0;
}

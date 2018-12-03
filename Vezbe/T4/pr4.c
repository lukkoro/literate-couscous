#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_a 100+1
#define MAX_b 20+1

int duzina_stringa(char *a) {
  int i=0;
  while(*a++!='\n' || *a) {
    i++;
  }

  return i;
}

void brojac_BuA(char *a, char *b) {
  int i, j;
  int size_a;
  int size_b;
  
  size_a = duzina_stringa(a);
  size_b = duzina_stringa(b);

  int equal;
  int k;
  int count = 0;
  for(i = 0; i < size_a; i++) {
    equal = 1;
    k = 0;
    for(j = 0; j < size_b; j++) {
      if(a[i+k]!=b[j]) {
        equal = 0;
        break;
      }
      k++;
    }
    if(equal) {
      count++;
    }
  }

  printf("String B se pojavljuje %d puta u stringu A\n", count);
}

int main () {
  char a[MAX_a];
  char b[MAX_b];

  do {
    printf("Unesite string a: ");
    fgets(a, MAX_a-1, stdin);
  } while(duzina_stringa(a)>MAX_a-1 || duzina_stringa(a)==0);

  do {
    printf("Unesite string b: ");
    fgets(b, MAX_b-1, stdin);
  } while(duzina_stringa(b)>MAX_b-1 || duzina_stringa(b)>duzina_stringa(a) || duzina_stringa(b)==0);

  printf("String a: %s\n", a);
  printf("String b: %s\n", b);

  brojac_BuA(a,b);
  
  
  return 0;
}
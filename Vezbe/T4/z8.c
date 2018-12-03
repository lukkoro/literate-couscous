#include <stdio.h>
#define MAX_SIZE 100+1

float stof(const char *s);
int strlength(char *s);

int main(){
    char s[MAX_SIZE];
    float f;
    
    fgets(s,MAX_SIZE,stdin);
    f = stof(s);
    printf("%f", f);



    return 0;
}

float stof(const char* s){
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};

int strlength(char *s) {
    int i = 0;
    while(*s!='.' || *s) {
        i++;
        *s++;
    }

    return i;
}
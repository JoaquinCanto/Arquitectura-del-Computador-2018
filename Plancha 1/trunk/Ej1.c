#include <stdio.h>
#include <stdlib.h>

printb(int n){
  int i;
  for(i = sizeof(int)*8 - 1; i >= 0; i--){
    if(n & 1 << i) printf("1");
    else printf("0");
    if(i%8 == 0) printf(" ");
  }
  puts("");
}

int main(){
  int a = 1 << 31;
  int b = (1 << 31) | (1 << 15);
  int c = -1 & 0xFFFFFF00;
  int d = 0xAA | (0xAA << 24);
  int e = 5 << 8;
  int f = -1 & (~ (1 << 8));

  printb(a);
  printb(b);
  printb(c);
  printb(d);
  printb(e);
  printb(f);

  return 0;
}
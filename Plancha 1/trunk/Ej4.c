#include <stdio.h>
#include <stdlib.h>

unsigned mult(unsigned a, unsigned b){

  if(b == 0) return 0;
  if(b == 1) return a;
  //Miramos el último bit de b, si b & 1 es 1, es impar, si no, es par.

  if(b & 1) return( mult(a << 1, b >> 1) + a);
  else return(mult(a << 1, b >> 1));
}

int main(){
  unsigned a = 5, b = 42, c;

  c = mult(a, b);

  printf("%u\n", c);

  return 0;
}

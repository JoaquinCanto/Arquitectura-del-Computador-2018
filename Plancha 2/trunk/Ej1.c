#include <stdio.h>
#include <math.h>
#include <ieee754.h>

int extSig(float l){
  return (*((unsigned int*) &l)) >> 31;
}

int extExp(float l){
	
  return (((*((unsigned int*) &l)) << 1) >> 24);
}

int extFrac(float l){
	return ((*((unsigned int*) &l) << 9) >> 9);
}

void printb(int n){
  int i;
  for(i = sizeof(int)*8 - 1; i >= 0; i--){
    if(n & 1 << i) printf("1");
    else printf("0");
    if(i%8 == 0) printf(" ");
  }
  puts("");
}

int main(){
	int s, e, f;
	
	float p = -2.625;
	
	s = extSig(p);
	e = extExp(p);
	f = extFrac(p);
	
	printf("Por funcion:\nSigno: %i\nExponente: %i\nFracción: %d\n\n", s, e, f);
	
	union ieee754_float l;
  l.f = -2.625;
  
  s = l.ieee.negative;
  e = l.ieee.exponent;
  f = l.ieee.mantissa;

  printf("Usando el header ieee_754:\nSigno: %i\nExponente: %i\nFracción: %d\n", s, e, f);
  
  return 0;
}

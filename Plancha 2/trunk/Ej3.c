#include <stdio.h>
#include <math.h>
#include <ieee754.h>

int main(){

	int s, e, f, f2;

	union ieee754_float f_avogadro;
	f_avogadro.f = 6.02252*pow(10, 23);

	union ieee754_double d_avogadro;
	d_avogadro.d = 6.02252*pow(10, 23);

	s = f_avogadro.ieee.negative;
	e = f_avogadro.ieee.exponent;
	f = f_avogadro.ieee.mantissa;

	printf("Usando la librería IEEE754:\nSigno: %i\nExponente: %i\nFracción: %d\n\n", s, e, f);

	s = d_avogadro.ieee.negative;
	e = d_avogadro.ieee.exponent;
	f = d_avogadro.ieee.mantissa0;
	f2= d_avogadro.ieee.mantissa1;

	long long int man = f;
	man = ((man << 32) | f2);

	printf("Usando la librería IEEE754:\nSigno: %i\nExponente: %i\nFracción: %lld\n", s, e, man);

	return 0;
}

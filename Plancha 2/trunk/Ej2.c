#include <stdio.h>

int extExp(float l){
	
  return (((*((unsigned int*) &l)) << 1) >> 24);
}

int extFrac(float l){
	return ((*((unsigned int*) &l) << 9) >> 9);
}

//1
int myisnan(float f){
	if((extExp(f) == 0xFF) && (extFrac(f) != 0)) return 1;
	else return 0;
}

//2
int myisnan2(float f){
	if(f == f) return 0;
	else return 1;
}

//3
int myisinfinity(float f){
	if((extExp(f) == 0xFF) && (extFrac(f) == 0)) return 1;
	else return 0;
}


int main(){
	float p = 0.0/0.0; //NAN
	float n = 1.0/0.0; //infinito
	float l = n+55;
	
	printf("P es NAN?: %d\t %d\n", myisnan(p), myisnan2(p));

	printf("Infinito es igual a infinito?: %d\n", myisinfinity(n));
	printf("Infinito sumado un valor, es infinito?: %d\n", myisinfinity(l));
	return 0;
}

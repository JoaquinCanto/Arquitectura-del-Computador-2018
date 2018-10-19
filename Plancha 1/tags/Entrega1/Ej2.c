#include <stdio.h>

void swap(int* a, int* b, int *c){
	*a = *a ^ *b ^ *c;
	*b = *a ^ *b ^ *c;
	*c = *a ^ *b ^ *c;
	*a = *a ^ *b ^ *c;
}

int main(){
	int a = 4, b = -72, c = 42;
	
	printf("Orden inicial: %i, %i, %i\n\n", a, b, c);
	
	swap(&a, &b, &c);
	
	printf("Orden final: %i, %i, %i\n", a, b, c); 
	
	return 0;
}

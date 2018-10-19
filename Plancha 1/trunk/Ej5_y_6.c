#include <stdio.h>
#include <gmp.h>

typedef struct{
	unsigned short n[16];
} nro;


void print(nro n){
	
	int i;
	char str[1024];
	short sign[16], num[16];
	mpz_t n1, n2;
	for (i=0; i<15; i++) {
		num[i] = n.n[i];
		sign[i] = 0;
	}
	num[15] = n.n[15] & 0x7FFF;
	sign[15] = n.n[15] & 0x8000;
	mpz_init(n1);
	mpz_init(n2);
	mpz_import(n1, 16, -1, 2, 0, 0, num);
	mpz_import(n2, 16, -1, 2, 0, 0, sign);
	mpz_neg(n2, n2);
	mpz_add(n2, n1, n2);
	mpz_get_str(str, 10, n2);
	printf("Número: %s\n", str);
	mpz_clear(n1);
	mpz_clear(n2);
}


int esCero(nro num){
	
	for(int i = 0; i < 16; i++){
		
		if(num.n[i]!=0) return 0;
	}
	
	return 1;
}


int esUno(nro num){
	
	for(int i = 1; i < 16; i++){
		
		if(num.n[i]!=0) return 0;
	}
	
	if(num.n[0]!=1) return 0;
	else return 1;
}
		
int esPar(nro num){
	
	short hexa = 0x0001;
	
	if(num.n[0]&hexa) return 0;
	else return 1;
}

nro corrIzq(nro num, int n){
	
	short inicio = 0x0001;
	
	inicio = inicio << 15;
	
	for(; n > 0; n--){
		
		for(int i = 15; i > 0; i--){
			
			short aux = 0x0000;
	
			num.n[i] = num.n[i] << 1;
			aux = (num.n[i-1]&inicio);
			num.n[i] = (num.n[i]|aux);
		}
		
		num.n[0] = num.n[0] << 1;
	}
	
	return num;
}

nro corrDer(nro num, int n){
	
	short final=0x0001;
	
	for(; n > 0; n--){
		
		for(int i = 0; i < 15; i++){
			
			short aux=0x0000;
			
			num.n[i] = num.n[i] >> 1;
			aux = (num.n[i+1]&final);
			num.n[i] = (num.n[i]|aux);
		}
		
		num.n[15] = num.n[15] >> 1;
	}
	
	return num;
}

nro suma(nro num1, nro num2){
	
	int acarreo=0, i;
	nro resultado;
	
	for(i = 0; i < 16; i++){
		
		resultado.n[i]=num1.n[i]+num2.n[i]+acarreo;
		int aux=num1.n[i]+num2.n[i];
		
		if(aux > ((1 << sizeof(unsigned short)*8) - 1)) acarreo = 1;
		else acarreo = 0;
	}
	
return resultado;
}

nro mult(nro num1, nro num2){
	
	if(esCero(num2)==1) return num2;
	
	else if(esUno(num2)==1) return num1;
	
	else if(esPar(num2)==1) return mult(corrIzq(num1, 1), corrDer(num2, 1));
			
	else return suma(mult(corrIzq(num1, 1), corrDer(num2, 1)), num1);
}
		
int main(){
	
	nro num1, num2;
	int i;
	for(i=0; i<16; i++){
		num1.n[i]=0;
		num2.n[i]=0;
	}
	
	num1.n[0]=0;
	num2.n[0]=1;
	
	puts("");
	
	print(num1);
	if(esCero(num1)) printf("El número es cero\n\n");
	print(num2);
	if(esUno(num2)) printf("El número es uno\n\n");
	print(num1);
	if(esPar(num1)) printf("El número es par\n\n\n");
	
	num1.n[0]=25;
	print(num1);
	
	printf("Corro 4 bits a la izquierda\n");
	
	num1 = corrIzq(num1, 4);
	print(num1);
	
	printf("Ahora, corro 2 bits a la derecha\n");
	
	num1 = corrDer(num1, 2);
	print(num1);
	
	printf("\n\n");
	
	
	num2.n[0]=50;
	print(num1);
	print(num2);
	
	printf("Sumo ambos valores\n");
	
	print(suma(num1, num2));
	
	printf("\n\n");
	
	
	num2.n[0]=0;
	print(num1);
	print(num2);
	
	printf("Multiplico ambos valores\n");
	
	print(mult(num1, num2));
	
	puts("");
	
	
	num2.n[0]=1;
	print(num1);
	print(num2);
	
	printf("Multiplico ambos valores\n");
	
	print(mult(num1, num2));
	
	puts("");
	
	
	num2.n[0]=3;
	print(num1);
	print(num2);
	
	printf("Multiplico ambos valores\n");
	
	print(mult(num1, num2));
	
	puts("");
	
	
	num2.n[0]=10;
	print(num1);
	print(num2);
	
	printf("Multiplico ambos valores\n");
	
	print(mult(num1, num2));
	
return 0;
}

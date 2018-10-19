#include <stdio.h>

typedef struct {
	unsigned short n[16];
} nro;

int par(nro num){
	
	short hexa = 0x0001;
	
	if(num.n[15]&hexa) return 1;
	else return 0;
}

/*void corrIzqByJuako(unsigned short arr[], int n){
	
	short hexa = 0x0001;
	int j;
	for(j = n; j>1; j--){
		hexa = hexa << 1;
		hexa += 0x0001;
	}
	
	hexa = hexa << (16-n);
	
	int i = 0;
	for(i=0; i<15; i++){
	
		arr[i] = arr[i] << n;

		short move = (arr[i+1] & hexa);

		move = move >> (15-n);

		arr[i] = arr[i] | move;
	}
}*/

void corrIzq(unsigned short arr[], int n){
	int i;
	short inicio=0x0001;
	inicio = inicio << 15;
	for(; n>0; n--){
		for(i=15; i>0; i--){
			arr[i] = arr[i] << 1;
			short aux=0x0000;
			aux=(arr[i-1]&inicio);
			arr[i]=(arr[i]|aux);
		}
		arr[0]=arr[0] << 1;
	}
}
int main(){
	
	nro num;
	int i;
	for(i=0; i<16; i++) num.n[i]=0;
	num.n[1]=1;
	
	print(num);
	
	corrIzq(num.n, 2);
	
	print(num);
	
return 0;
}

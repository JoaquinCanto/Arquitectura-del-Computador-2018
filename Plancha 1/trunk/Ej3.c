#include <stdio.h>
#include <stdlib.h>


void codificacion(int codificador){
  char c;
  int codificado;

  while((c = getchar()) != EOF){
    codificado = c ^ codificador;
    printf("%c", codificado);
  }
}

int main(int argc, char *argv[]){
  int arg = atoi(argv[1]);

  codificacion(arg);

  return 0;
}
//dar a la consola el comando: ./ej3 42 | hexdump -C

/*¿Se gana algo codificando algo más de una vez?
No, ya que el resultado vuelve a ser lo mismo que la entrada.*/

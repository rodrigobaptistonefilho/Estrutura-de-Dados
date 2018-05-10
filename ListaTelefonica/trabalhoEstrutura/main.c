#include "stdio.h"
#include "trabalhoEstrutura.c"
#include "trabalhoEstrutura.h"
//Trabalho feito com a ajudo dos alunos Thiago, Willian e Vitor.

//Nome: <Rodrigo Baptistone Filho>

//RA: <120187>

//Trabalho <lista sequencial estatica - lista telefonica>


int main(){

      LISTA lista;
      REGISTRO r;
      inicializar(&lista);

        //inseri os elementos na lista
        //const, é constante do tipo registro que vai receber na ordem
        r = (const REGISTRO){"Rodrigo","Av. Edelina Meneghel Rando", 998060492};
        inserir(&lista, r);

        r = (const REGISTRO){"Jose","Av. Edelina Meneghel Rando", 997273338};
        inserir(&lista, r);

        r = (const REGISTRO){"Thiago","Av. Comendador Luiz Meneghel", 996069321};
        inserir(&lista, r);

        printf("Tamanho da lista: %d\n", tamanho(&lista) );

      exibir(&lista);
      reinicializar(&lista);
  return 0;
}

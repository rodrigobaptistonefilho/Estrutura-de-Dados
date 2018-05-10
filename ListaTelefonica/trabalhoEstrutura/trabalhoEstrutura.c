#include "trabalhoEstrutura.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//A Inicializa��o da lista definindo o tamanho inicial dela como 0
void inicializar(LISTA *l){
  l -> cont = 0;
}
//Retorna o tamanho da lista no qual ela se encontra
int tamanho(LISTA *l){
  return l -> cont;
}
//Foi aplicado o algoritmo Inserction Sort na fun��o inserir os elementos na lista
void inserir(LISTA *l, REGISTRO r){
  int i;
//if para verificar se a lista esta cheia
//Caso esteja ele retorna uma mensagem
  if(l->cont >= SIZE){
    printf("A lista esta cheia!\n");
    return;
  }
    // algoritmo insertion sort para inserir por ordem de nome
    //vai verificar se o nome atual � menor que o anterior
  for(i = l->cont; i > 0 && strcmp(r.nome, l -> registro[i-1].nome) < 0; i--){
    l -> registro[i] = l -> registro[i - 1];
  }

  l -> registro[i] = r;
  l -> cont = l->cont +1;
}
void exibir(LISTA *l){
    int i;
    //Primeiro um if para ver se a lista est� vazia, caso esteja ele vai exibir uma mensagem
    if(tamanho(l) == 0)
  {
    printf("A lista esta vazia!");
  }
  /*Loop que a vari�vel i vai variar de 0 que � a primeira posi��o de um elemento
da lista e enquanto a vari�vel i for menor que o n�mero de elemento, ou seja,
o i vai percorrer cada elemento at� o �ltimo elemento da lista*/

  for(i = 0; i < l-> cont; i++){
    puts("----------------------------------------");
    printf("Nome: %s\n", l->registro[i].nome);
    printf("Endereco: %s\n", l->registro[i].endereco);
    printf("Telefone: %d\n", l->registro[i].telefone);

  }
}
//Para reinicializar a lista basta colocar 0 no campo cont para resetar
void reinicializar(LISTA *l){
l->cont = 0;
}

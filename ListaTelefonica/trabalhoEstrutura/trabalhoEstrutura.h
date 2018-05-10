#ifndef TRABALHOESTRUTURA_H_INCLUDED
#define TRABALHOESTRUTURA_H_INCLUDED
#include <stdio.h>
#define TAM 30
#define SIZE 5

//Dados no qual a lista vai ter
typedef char NOME;
typedef char ENDERECO;
typedef int TELEFONE;

//As struct para armazenar os dados
typedef struct{
  NOME nome[TAM];
  ENDERECO endereco[TAM];
  TELEFONE telefone;

}REGISTRO;

//Declaração da lista
typedef struct{
  REGISTRO registro[SIZE];
  int cont;

}LISTA;

//PROTÓTIPO e FUNÇÕES
void inicializar(LISTA *l);
int tamanho(LISTA *l);
void inserir(LISTA *l, REGISTRO r);
void exibir(LISTA *l);
void reinicializar(LISTA *l);

#endif //TRABALHOESTRUTURA_H_INCLUDED

#ifndef TRABALHOB_H_INCLUDED
#define TRABALHOB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

//Dados no qual a lista vai ter
typedef char NOME;
typedef double PRECO;
typedef int IDADE;
typedef char PAIS;
typedef int CODIGO;
typedef int QUANTIDADE;

//As struct para armazenar os dados
typedef struct{
    NOME nome[TAM];
    PRECO preco;
    IDADE idade;
    PAIS pais[TAM];
    CODIGO codigo;
    QUANTIDADE quantidade;

}REGISTRO;

typedef struct aux{
    REGISTRO reg;
     struct exemplo *prox ;
}ELEMENTO;

typedef ELEMENTO* PONT;

//Declaração da lista
typedef struct{
    PONT inicio;
}LISTA;

//PROTÓTIPO e FUNÇÕES
void menu();
void inicializar(LISTA *l);
void insercaoIdade(LISTA *l, REGISTRO elem);
void insercaoQuant(LISTA *l, REGISTRO elem);
void insercaoPais(LISTA *l, REGISTRO elem);
void exibirLista(LISTA *l);
PONT buscaElemOrd(LISTA *l, int cb);
void exlcuir(LISTA *l, int ce);
void reinicializar(LISTA *l);

#endif // TRABALHOB_H_INCLUDED

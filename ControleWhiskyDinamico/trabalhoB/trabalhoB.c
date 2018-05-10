#include "trabalhoB.h"
#include <stdio.h>
#include <stdlib.h>

// o usuário vai escolher qual da opções esse deseja ordenar a lista
void menu(){
    printf("Qual a ordem que deseja ordenar os produtos?");
    printf("\n1 - Idade\n");
    printf("2 - Quantidade\n");
    printf("3 - Pais\n");

}

/* colocar início igual a null que indica
que não tem nenhum elemento valido na estrutura */
void inicializar(LISTA *l){
    l->inicio=NULL;
}

/* criamos um endereço começando do primeiro endereço valido
e enquanto o endereço for diferente de null imprimi os elementos
e no final o endereço recebe o próximo endereço */
void exibirLista(LISTA *l){
    PONT aux= l->inicio;

while(aux!=NULL){
    printf("\nNOME: %s\n", aux->reg.nome);
    printf("PRECO: %.2lf\n", aux->reg.preco);
    printf("IDADE: %d\n", aux->reg.idade);
    printf("PAIS: %s\n", aux->reg.pais);
    printf("CODIGO: %d\n", aux->reg.codigo);
    printf("QUANTIDADE NO ESTOQUE: %d\n", aux->reg.quantidade);
    aux=aux->prox;
}
}

/* A função inserir é igual para idade, pais e quantidade. O unico diferencial é que
pais é string.
A inserção acontece ordenada, pelo valor do elemento do registro passado e sem
permitir a inserção de elementos repetidos. É necessário descobrir qual o elemento
é o anterior e o proximo.
Aloca-se memória para o novo elemento. */
void insercaoIdade(LISTA *l, REGISTRO elem){
    PONT atual = NULL;
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
    puts("\nIdade nao inserido\n");

}
    novo->reg=elem;
    novo->prox=NULL;
    atual=l->inicio;

    while(atual!=NULL && atual->reg.idade<elem.idade){
    ant=atual;
    atual = atual->prox;
}
    novo->prox=atual;

    if(ant==NULL){
    l->inicio=novo;
}
    else{
    ant->prox=novo;
}
}

void insercaoPais(LISTA *l, REGISTRO elem){
    PONT atual = NULL;
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
    puts("\nPais nao inserido\n");
}

    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && strcmp(atual->reg.pais,elem.pais)<0){
    ant=atual;
    atual = atual->prox;
}
    novo->prox=atual;

if(ant==NULL){
    l->inicio=novo;
}
else{
    ant->prox=novo;
}
}

void insercaoQuant(LISTA *l, REGISTRO elem){
    PONT atual = NULL;
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
    puts("\nQuantidade nao inserido\n");

}
    novo->reg=elem;
    novo->prox=NULL;
    atual=l->inicio;

    while(atual!=NULL && atual->reg.quantidade<elem.quantidade){
    ant=atual;
    atual = atual->prox;
}
    novo->prox=atual;

    if(ant==NULL){
    l->inicio=novo;
}
    else{
    ant->prox=novo;
}
}

/* vai rebecer do usuario um codigo e retorna o
endereço em que o elemento se encontra
caso o elementro não seja encontrado retorna
null*/
PONT buscaElemOrd(LISTA *l, int cb){

    PONT aux= l->inicio;

    while(aux!=NULL && aux->reg.codigo<cb){
    aux=aux->prox;
}
    if(aux!=NULL && aux->reg.codigo==cb){
    return aux;
}
    else{
    return NULL;
}
}

/* O usuário passa o codigo do produto que ele pretende excluir.
Se houver este elemento na lista, o exclui e acerta os ponteiros
envolvidos */
void exlcuir(LISTA *l, int ce){
    PONT atual= l->inicio;
    PONT ant=NULL;

    while(atual!=NULL && atual->reg.codigo<ce){
    ant = atual;
    atual = atual->prox;
}
    if(atual==NULL){
    puts("Produto nao encontrado\n");
}
    else{
    if(atual->reg.codigo!=ce){
        puts("\nCodigo nao foi excluido pois nao esta na lista\n");
    }
    else{
        if(ant==NULL){
            l->inicio=atual->prox;
        }
        else{
                ant->prox=atual->prox;
        }

        free(atual);
        puts("\n\nProduto excluido");
    }
}
}

/* Na reinicialização da estrutura, precisamos excluir todos os seus
elementos e atualizar o inicio para NULL */
void reinicializar(LISTA *l){
    PONT aux=l->inicio;

    while(aux!=NULL){
    l->inicio=l->inicio->prox;
    free(aux);
    aux=l->inicio;
}
}

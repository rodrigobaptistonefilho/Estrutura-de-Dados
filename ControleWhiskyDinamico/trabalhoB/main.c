#include <stdio.h>
#include <stdlib.h>
#include "trabalhoB.h"

//Nome: <Rodrigo Baptistone Filho>

//RA: <120187>

//Trabalho <Lista Simplesmente Encadeada Dinâmica - Controle Estoque>

int main()
{
    LISTA lista;
    REGISTRO elem;
    PONT aux = NULL;
    int opcao = 0;

    inicializar(&lista);

    menu();
    scanf("%d", &opcao);

    //caso a opção que o usuario digitar no menu seja diferente ele vai limpar a tela e retorna a main
    if(opcao!=1 && opcao!= 2 && opcao!=3){
    system("cls");
    return main();
    }

    //inseri os elementos na lista
    //const, é constante do tipo registro que vai receber na ordem os dados no qual vai ser inserido
    elem = (const REGISTRO){"Chivas Regal ", 127.90, 12, "Escocia", 1, 100};
    if(opcao == 1)insercaoIdade(&lista, elem);
    else if(opcao == 2)insercaoQuant(&lista, elem);
    else if(opcao == 3)insercaoPais(&lista, elem);

    elem = (const REGISTRO){"Jack Daniels", 115.20, 62, "Estados Unidos", 2, 50};
    if(opcao == 1)insercaoIdade(&lista, elem);
    else if(opcao == 2)insercaoQuant(&lista, elem);
    else if(opcao == 3)insercaoPais(&lista, elem);

    //ele exibi no começo do codigo qual foi a opção que o usuario escolheu para ordenar o elemento
    system("cls");
    if(opcao == 1) printf("Ordenado por Idade:\n\n");
    else if(opcao == 2) printf("Ordenado por Quantidade:\n\n");
    else if(opcao == 3) printf("Ordenado por Pais:\n\n");
    exibirLista(&lista);

    //realizado a busca do elemento ordenadamente
    aux = buscaElemOrd(&lista, elem.codigo);

    if(buscaElemOrd(&lista, elem.codigo)!=NULL){
    printf("\n\nBusca por codigo:\n\n");
    printf("NOME: %s\n", aux->reg.nome);
    printf("PRECO: %.2lf\n", aux->reg.preco);
    printf("IDADE: %d\n", aux->reg.idade);
    printf("PAIS: %s\n", aux->reg.pais);
    printf("CODIGO: %d\n", aux->reg.codigo);
    printf("QUANTIDADE NO ESTOQUE: %d\n", aux->reg.quantidade);
}
    else{
    printf("O elemento nao esta na lista\n");
}
    //a exclusão do codigo no qual o usuario digitou que no caso é o 1
    printf("\n\nExclusao por codigo:");
    exlcuir(&lista, elem.codigo = 1);

    exibirLista(&lista);
    reinicializar(&lista);
    return 0;
}

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

#include "produtos.h"


struct ProdutosBase {
    char nome[50];
    float preco;
    int quantidade;
};

struct ProdutosBase* products;
int qntProdutos = 16;

struct Funcionarios {
    char nome[50];
    int idade;
    char cpf[12];
    char rg[10];
    char email[50];
    char senha[25];
    char cep[9];
};

int quantidadeFuncionarios = 0;
struct Funcionarios* funcionarios;

void inicializarEstoque(){
    srand(time(NULL));
    funcionarios = (struct Funcionarios*)malloc(quantidadeFuncionarios * sizeof(struct Funcionarios));
    for(int i = 0; i < 16; i++){
        estoque[i] = rand() % 10;
    }
}

void listarEReporEstoque(){
    system("cls");
    printf("Estoque atual: \n");
    for(int i = 0; i < qntProdutos; i++){
        printf("%d - %s Quantidade: %d unidades\n", i + 1, products[i].nome, products[i].quantidade);
    }
    printf("Deseja repor algum item? [Digite 0 para retornar] ");
    int opt;
    scanf("%d", &opt);

    if(opt == 0){
        system("cls");
        return;
    } else {
        if(opt <= qntProdutos){
            printf("Quantos itens voce deseja repor ao produto %s? ", products[opt - 1].nome);
            int qnt;
            scanf("%d", &qnt);
            products[opt - 1].quantidade += qnt;
        }
    }
    system("cls");
}

void InicializarProdutosPtr(){
    products = (struct ProdutosBase*)malloc(16 * sizeof(struct ProdutosBase));

    for(int i = 0; i < 16; i++){
        strcpy(products[i].nome, produtos[i]);
        products[i].preco = precoMedio[i];
        products[i].quantidade = estoque[i];
    }
}

void addProduto(){
    fflush(stdin);
    system("cls");
    qntProdutos += 1;
    products = (struct ProdutosBase*)realloc(products, qntProdutos * sizeof(struct ProdutosBase));

    printf("Qual produto deseja adicionar? ");
    gets(products[qntProdutos - 1].nome);
    fflush(stdin);
    printf("Quanto custa o produto? ");
    scanf("%f", &products[qntProdutos - 1].preco);
    printf("Quantos itens estarao disponiveis inicialmente no estoque? ");
    scanf("%d", &products[qntProdutos - 1].quantidade);
    system("cls");
    printf("Produto cadastro com sucesso!\n");
}

void addFuncionario(){
    fflush(stdin);
    quantidadeFuncionarios += 1;
    funcionarios = (struct Funcionarios*)realloc(funcionarios, quantidadeFuncionarios * sizeof(struct Funcionarios));
    printf("Registro de Funcionario: \n");
    printf("Nome: ");
    gets(funcionarios[quantidadeFuncionarios - 1].nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &funcionarios[quantidadeFuncionarios - 1].idade);
    printf("CEP: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].cep);
    printf("CPF: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].cpf);
    printf("RG: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].rg);
    printf("E-mail: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].email);
    printf("Senha: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].senha);
    system("cls");
    printf("Funcionario adicionado com sucesso!\n");
}

void listarFuncionarios(){
    for(int i = 0; i < quantidadeFuncionarios; i++){
        printf("[%d] - %s\n", i + 1, funcionarios[i].nome);
    }
    int opt;
    if(quantidadeFuncionarios > 0){
        printf("De qual funcionario voce deseja ver mais detalhes? [0 para retornar]");
        scanf("%d", &opt);

        if(opt == 0){
            system("cls");
        } else if(opt <= quantidadeFuncionarios){
            system("cls");
            printf("Funcionario %s:\n", funcionarios[opt - 1].nome);
            printf("Idade: %d\n", funcionarios[opt - 1].idade);
            printf("E-mail: %s\n", funcionarios[opt - 1].email);
            printf("CEP: %s\n", funcionarios[opt - 1].cep);
            printf("CPF: %s\n", funcionarios[opt - 1].cpf);
            printf("RG: %s\n", funcionarios[opt - 1].rg);
            printf("Senha de Login: %s\n\n", funcionarios[opt - 1].senha);
            printf("Acoes:\n");
            printf("[1] - Demitir\n");
            printf("[2] - Retornar\n");
            printf("Escolha uma opcao: ");
            int opt2;
            scanf("%d", &opt2);
            struct Funcionarios funcionarioDemitido = funcionarios[opt - 1];
            switch(opt2){
                case 1:
                    for(int i = 1; i < quantidadeFuncionarios; i++){
                        funcionarios[i - 1] = funcionarios[i];
                    }
                    funcionarios[quantidadeFuncionarios - 1] = funcionarioDemitido;
                    quantidadeFuncionarios -= 1;
                    funcionarios = (struct Funcionarios*)realloc(funcionarios, quantidadeFuncionarios * sizeof(struct Funcionarios));
                    system("cls");
                    break;
                default:
                    system("cls");
                    listarFuncionarios();
                    break;
            }
        }
    } else {
        printf("Nao existe nenhum funcionario contratado no momento.\n");
    }
}
#endif
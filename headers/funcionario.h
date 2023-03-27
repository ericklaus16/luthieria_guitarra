#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#include "produtos.h"

struct Funcionarios {
    char nome[50];
    int idade;
    char cpf[12];
    char rg[10];
    char email[50];
    char senha[25];
};

int quantidadeFuncionarios = 0;
struct Funcionarios* funcionarios;

int criouEstoque = 0;

void inicializarEstoque(){
    srand(time(NULL));
    funcionarios = (struct Funcionarios*)malloc(quantidadeFuncionarios * sizeof(struct Funcionarios));
    for(int i = 0; i < 16; i++){
        estoque[i] = rand() % 10;
    }
}

void listarEReporEstoque(){
    if(criouEstoque == 0){
        inicializarEstoque();
        criouEstoque = 1;
    }

    system("cls");
    printf("Estoque atual: \n");
    for(int i = 0; i < 16; i++){
        printf("%d - %s Quantidade: %d unidades\n", i + 1, produtos[i], estoque[i]);
    }
    printf("Deseja repor algum item? [Digite 0 para retornar]");
    int opt;
    scanf("%d", &opt);

    if(opt == 0){
        return;
    } else {
        if(opt <= 16){
            printf("Quantos itens você deseja repor ao produto %s? ", produtos[opt - 1]);
            int qnt;
            scanf("%d", &qnt);
            estoque[opt - 1] += qnt;
        }
    }

}

void addProduto(){
    system("cls");
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
    printf("CPF: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].cpf);
    printf("RG: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].rg);
    printf("E-mail: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].email);
    printf("Senha: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios - 1].senha);
}
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
    char cep[9];
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
            printf("Quantos itens voce deseja repor ao produto %s? ", produtos[opt - 1]);
            int qnt;
            scanf("%d", &qnt);
            estoque[opt - 1] += qnt;
        }
    }
    system("cls");
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

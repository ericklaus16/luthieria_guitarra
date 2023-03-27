#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcionario.h"

#include "montar.h"
#include "comprar.h"
#include "compraPecas.h"

void logar();
void alocarUsuarios();
void cadastrarUsuario();
void logarUsuario();
void montarLoja();

int ehFuncionario = 0;

struct Usuario {
    char email[50];
    char senha[25];
    int admin;
};

struct Usuario* usuarios;

int qntUsuarios = 1;

void alocarUsuarios(){
    usuarios = (struct Usuario*) malloc(qntUsuarios * sizeof(struct Usuario));
    strcpy(usuarios[0].email, "admin");
    strcpy(usuarios[0].senha, "admin");
    usuarios[0].admin = 1;
}

void cadastrarUsuario(){
    fflush(stdin);
    qntUsuarios += 1;
    usuarios = (struct Usuario*) realloc(usuarios, qntUsuarios * sizeof(struct Usuario));

    usuarios[qntUsuarios - 1].admin = 0;
    printf("Cadastro de Usuario: \n");
    printf("Email do utilizador: ");
    gets(usuarios[qntUsuarios - 1].email);
    fflush(stdin);
    printf("Senha do utilizador: ");
    scanf("%s", &usuarios[qntUsuarios - 1].senha);
    fflush(stdin);
    system("cls");
    printf("Usuario cadastrado com sucesso!\n");
    logar();
}

void logarUsuario(){
    fflush(stdin);
    char email[50];
    char senha[25];

    system("cls");
    printf("Area do Usuario: \n");
    printf("Email: ");
    gets(email);
    fflush(stdin);
    printf("Senha: ");
    scanf("%s", &senha);
    fflush(stdin);

    // Verificar se o login foi correto
    int auth = 0;

    for(int i = 0; i < qntUsuarios; i++){
        if(!strcmp(email, usuarios[i].email)){
            if(!strcmp(senha, usuarios[i].senha)){
                auth = 1;
                ehFuncionario = usuarios[i].admin;
            } 
        } 
    }

    if(auth == 1){
        system("cls");
        printf("Logado com sucesso.\n");
        montarLoja();
    }   else {
        system("cls");
        printf("E-mail ou senha incorretos. Tente novamente.\n");
        logar();
    }
}

void montarLoja(){
    printf("O que deseja fazer hoje? \n");
    if(ehFuncionario == 0){
        // Cliente
        int opcao;
        printf("[1] Montar sua propria guitarra\n");
        printf("[2] Comprar uma guitarra com vendedores\n");
        printf("[3] Compra de produtos relacionados\n"); // Amps, cabos, e pa
        printf("[4] Retornar para o menu.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                criar();
                montarLoja();
                break;
            case 2:
                presets();
                montarLoja();
                break;
            case 3:
                comprarPecas();
                montarLoja();
                break;
            case 4:
                system("cls");
                logar();
                break;
            default:
                break;
        }
    } else {
        // Funcionario
        int opcao;
        printf("[1] Repor estoque de produtos\n");
        printf("[2] Adicionar novo produto a loja\n");
        printf("[3] Adicionar funcionario\n"); // Amps, cabos, e pa
        printf("[4] Retornar para o menu.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                listarEReporEstoque();
                montarLoja();
                break;
            case 2:
                addProduto();
                montarLoja();
                break;
            case 3:
                addFuncionario();
                qntUsuarios += 1;
                usuarios = (struct Usuario*)realloc(usuarios, qntUsuarios * sizeof(struct Usuario));
                strcpy(usuarios[qntUsuarios - 1].email, funcionarios[quantidadeFuncionarios - 1].email);
                strcpy(usuarios[qntUsuarios - 1].senha, funcionarios[quantidadeFuncionarios - 1].senha);
                usuarios[qntUsuarios - 1].admin = 1;
                montarLoja();
                break;
            case 4:
                system("cls");
                logar();
                break;
            default:
                break;
        }
    }
}

void logar(){
    printf("Bem-vindo ao sistema da melhor loja de guitarras do mundo!\n");
    printf("[1] Cadastro de Usuario\n");
    printf("[2] Login\n");
    printf("[3] Encerrar aplicacao\n");

    int opcao;
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            logarUsuario();
            break;
        case 3:
            printf("Programa encerrado.");
            break;
        default:
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            logar();
            break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "montar.h"
#include "comprar.h"
#include "vender.h"

void logar();
void alocarUsuarios();
void cadastrarUsuario();
void logarUsuario();
void montarLoja();

struct Usuario {
    char email[50];
    char senha[25];
};

struct Usuario* usuarios;

int qntUsuarios = 0;

void alocarUsuarios(){
    usuarios = (struct Usuario*) malloc(qntUsuarios * sizeof(struct Usuario));
}

void cadastrarUsuario(){
    fflush(stdin);
    qntUsuarios += 1;
    usuarios = (struct Usuario*) realloc(usuarios, qntUsuarios * sizeof(struct Usuario));

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
    int opcao;
    printf("O que deseja fazer hoje? \n");
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
            //comprar();
            break;
        case 3:
            //vender();
            break;
        case 4:
            system("cls");
            logar();
            break;
        default:
            break;
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

#include <stdio.h>
#include <stdlib.h>
#include "montar.h"
#include "comprar.h"
#include "vender.h"

struct Usuario {
    char email[50];
    char senha[25];
};

void logar(){
    printf("Bem-vindo ao sistema da melhor loja de guitarras do mundo!\n");
    printf("[1] Cadastro de Usuario\n");
    printf("[2] Login\n");

    montarLoja();
}

void montarLoja(){
    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            montar();
            break;
        case 2:
            break;
        default:
            montarLoja();
    }
}
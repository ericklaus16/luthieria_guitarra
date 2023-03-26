#include <stdio.h>
#include <stdlib.h>
#include "montar.h"
#include "comprar.h"
#include "vender.h"

struct Usuario {
    char email[50];
    char senha[25];
};

void montarLoja(){
    int opcao;
    printf("O que deseja fazer hoje? \n");
    printf("[1] Montar uma guitarra customizada\n");
    printf("[2] Comprar uma guitarra com vendedores\n");
    printf("[3] Vender uma guitarra\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            criar();
            break;
        case 2:
            //comprar();
            break;
        case 3:
            //vender();
            break;
    }
}

void logar(){
    printf("Bem-vindo ao sistema da melhor loja de guitarras do mundo!\n");
    printf("[1] Cadastro de Usuario\n");
    printf("[2] Login\n");

    montarLoja();
}

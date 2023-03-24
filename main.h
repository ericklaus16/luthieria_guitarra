#include <stdio.h>
#include <stdlib.h>

struct Usuario {
    char email[50];
    char senha[25];
};

void logar(){
    printf("Bem-vindo ao sistema da melhor loja de guitarras do mundo!\n");
    printf("[1] Cadastro de Usuario\n");
    printf("[2] Login\n");
}
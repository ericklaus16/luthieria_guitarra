#include <stdio.h>
#include <stdlib.h>
#include "guitarra.h"

/*

*/

void criar(){
    system("CLS");
    printf("Bem-vindo a area de criacao de guitarras.\n");
    struct Guitar guitarra = criarGuitarra();
}
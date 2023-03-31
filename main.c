#include <stdio.h>
#include <stdlib.h>
#include "./headers/main.h"
#include "./headers/comprar.h"
#include "./headers/funcionario.h"

int main(){
    inicializarEstoque();
    InicializarProdutosPtr();
    alocarUsuarios();
    presets();
    logar();

    return 0;
}
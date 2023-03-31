#ifndef PECAS_H
#define PECAS_H
#include "pagamento.h"
#include "produtos.h"

void comprarPecas(){
    for (int i = 0; i < qntProdutos; i++){
        printf("%d - %s (%d unidades) R$%.2f \n",i+1 , products[i].nome, products[i].quantidade, products[i].preco);
    }
    int opt;
    printf ("\nQual produto voce deseja comprar? [Digite 0 para retornar] ");
    scanf ("%d", &opt);
    if(opt == 0){
        system("cls");
        return;
    } else if(opt >= 1 && opt <= qntProdutos){
        if(products[opt - 1].quantidade > 0){
            int parcelas;
            int metodoPagamento = pagar(products[opt-1].preco, &parcelas);
            products[opt-1].quantidade -= 1;
        } else {
            system("cls");
            printf("O produto nao esta disponivel no momento. Tente novamente mais tarde!\n");
        }
    } else {
        system("cls");
        printf("A opcao digitada eh invalida.\n");
    }

}
#endif
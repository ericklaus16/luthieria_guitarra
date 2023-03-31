#include "pagamento.h"
#include "produtos.h"

void comprarPecas(){
    for (int i = 0; i < 16; i++){
        printf("%d - %s (%d unidades) R$%.2f \n",i+1 , produtos[i], estoque[i], precoMedio[i]);
    }
    int opt;
    printf ("\nQual produto voce deseja comprar? [Digite 0 para retornar] ");
    scanf ("%d", &opt);
    if(opt == 0){
        return;
    } else if(opt >= 1 && opt <= 16){
        int parcelas;
        int metodoPagamento = pagar(precoMedio[opt-1], &parcelas);
        estoque[opt-1] -= 1;
    } else {
        printf("A opcao digitada eh invalida.\n");
    }

    
}
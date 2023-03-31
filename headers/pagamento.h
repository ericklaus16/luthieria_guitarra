#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include <stdio.h>
#include <stdlib.h>

int pagar(float preco, int* parcelas){
    printf("Esta sendo iniciado agora o processo de pagamento da sua nova guitarra no valor de R$%.2f!\n", preco);
    printf("OBS: Lembre-se, nos da ERGuitars nunca enviaremos mensagens pedindo seus dados bancarios.\n");
    printf("Qual metodo de pagamento deseja utilizar?\n");
    printf("1 - Boleto Bancario (parcelado)\n");
    printf("2 - PIX (10%% de desconto)\n");
    printf("3 - Cartao de Credito\n");

    int opt;
    scanf("%d", &opt);
    system("cls");
    if(opt == 1){
        int aux;
        printf("Qual o numero de parcelas?\n");
        scanf("%d", &aux);
        *parcelas = aux;
        printf("Parabens! A compra foi efetuada com sucesso. O valor da parcela sera de R$%.2f\n", preco / *parcelas);
    } else if (opt == 2){
        printf("Parabens! A compra foi efetuada com sucesso. O valor com desconto sera de R$%.2f\n", 0.9 * preco);
    } else if (opt == 3){
        printf("Parabens! A compra foi efetuada com sucesso. O valor a vista sera de R$%.2f\n", preco);
    } else {
        printf("Opcao invalida!\n");
        return 0;
    }

    return opt;
}
#endif
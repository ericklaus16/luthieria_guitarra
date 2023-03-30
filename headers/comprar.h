#ifndef COMPRAR_H
#define COMPRAR_H

#include"pecasGuitarraManufatura.h"
#include "guitarra.h"
#include "time.h"
#include "pagamento.h"

struct Guitar guitarras[7];

void tirarRepeticoes(struct Guitar* guitarrasFuncao){
    srand(time(NULL));
    int repeat = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(i != j){
                if(!strcmp(guitarrasFuncao[i].nome, guitarrasFuncao[j].nome)){
                    strcpy(guitarrasFuncao[j].nome, modelGuitar[rand() % 15]);
                    repeat = 1;
                }
            }
        }
    }
}

void presets(){
    int value = 0;
    srand(time(NULL));

    for(int i = 0; i < 7; i++){
        guitarras[i].preco = 0;

        value = rand() % 3;
        strcpy(guitarras[i].body.tipo, tiposBody[value]);
        guitarras[i].preco += valoresBody[value];

        value = rand() % 2;
        guitarras[i].preco += valoresBridges[value];
        strcpy(guitarras[i].bridge.tipo, tiposBridge[value]);

        value = rand() % 3;
        guitarras[i].preco += valoresNut[value];
        strcpy(guitarras[i].nut.tipo, tiposNut[value]);

        value = rand() % 4;
        guitarras[i].preco += valoresMadeiraNeck[value];
        strcpy(guitarras[i].neck.tonewood.nome, tiposMadeira[value]);

        value = rand() % 2;
        guitarras[i].preco += valoresCaptadores[value];
        strcpy(guitarras[i].pickups.tipo, tiposPickups[value]);
        
        value = rand() % 4;
        guitarras[i].preco += valoresMadeiraHeadstock[value];
        strcpy(guitarras[i].headstock.tonewood.nome, tiposMadeira[value]);

        value = rand() % 4;
        strcpy(guitarras[i].strings.marca, marcasStrings[value]);

        value = rand() % 4;
        guitarras[i].preco += valoresStrings[value];
        strcpy(guitarras[i].strings.tamanho, tamanhosStrings[value]);

        value = rand() % 15;
        strcpy(guitarras[i].nome, modelGuitar[value]);

        value = rand() % 3;
        guitarras[i].preco += valoresHeadstock[value];
        strcpy(guitarras[i].headstock.tipo, tiposHeadstock[value]);
    }

    tirarRepeticoes(guitarras);
}

void comprarPreset(){
    printf("Esta disponivel hoje os seguintes modelos: \n");
    for (int i = 0; i < 7; i++){
        printf ("%d - %s R$%.2f\n",i+1, guitarras[i].nome, guitarras[i].preco);
    }
    int i = 0;
    printf ("\nQual guitarra voce deseja comprar? ");
    scanf ("%i", &i);
    printf ("\nNome da guitarra: %s \nTipo do corpo: %s \nTipo de ponte: %s \nTipo de captador: %s \nTipo de headstock: %s \nTipo de nut: %s \nTipo de madeira do braco: %s \nMarca da corda: %s \nTamanho da corda: %s \n", guitarras[i-1].nome, guitarras[i-1].body.tipo, guitarras[i-1].bridge.tipo, guitarras[i-1].pickups, guitarras[i-1].headstock.tipo, guitarras[i-1].nut.tipo, guitarras[i-1].neck.tonewood.nome, guitarras[i-1].strings.marca, guitarras[i-1].strings.tamanho);
    int parcelas;
    int metodoPagamento = pagar(guitarras[i-1].preco, &parcelas);
    criarRelatorio(guitarras[i-1], metodoPagamento, parcelas);
}
#endif
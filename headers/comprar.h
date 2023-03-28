#ifndef COMPRAR_H
#define COMPRAR_H

#include"pecasGuitarraManufatura.h"
#include "guitarra.h"
#include "time.h"

struct Guitar guitarras[7];

void presets(){
    int value = 0;
    printf("Esta disponivel hoje os seguintes modelos: \n");
    srand(time(NULL));

    for(int i = 0; i < 7; i++){
        guitarras[i].preco = 0;

        value = rand() % 3;
        guitarras[i].preco += valoresBody[value];
        strcpy(guitarras[i].body.tipo, tiposBody[value]);

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

        value = rand() % 3;
        guitarras[i].preco += valoresHeadstock[value];
        strcpy(guitarras[i].headstock.tipo, tiposHeadstock[value]);

        value = rand() % 4;
        strcpy(guitarras[i].strings.marca, marcasStrings[value]);

        value = rand() % 4;
        guitarras[i].preco += valoresStrings[value];
        strcpy(guitarras[i].strings.tamanho, tamanhosStrings[value]);

        value = rand() % 15;
        strcpy(guitarras[i].nome, modelGuitar[value]);
    }
}

void comprarPreset(){
    for (int i = 0; i < 7; i++){
        printf ("%d - %s\n",i+1, guitarras[i].nome);
    }
}
#endif
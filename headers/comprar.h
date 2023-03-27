#include"pecasGuitarraManufatura.h"
#include "guitarra.h"
#include "time.h"

void presets(){
    printf("Esta disponivel hoje os seguintes modelos: \n");
    srand(time(NULL));
    struct Guitar guitarras[7];

    for(int i = 0; i < 7; i++){
        strcpy(guitarras[0].body.tipo, tiposBody[rand() % 3]);
        strcpy(guitarras[0].bridge.tipo, tiposBridge[rand() % 2]);
    }
}
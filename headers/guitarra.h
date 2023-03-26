#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produtos.h"

#pragma region Structs
struct Tonewood {
    char nome[50];
    char descricao[300];
    float preco;
};

struct Headstock {
    char tipo[15];
    float preco;

    struct Tonewood tonewood;
};

struct Neck {
   struct Tonewood tonewood;
};

struct Body {
    char tipo[15];
};

struct Bridge {
    char tipo[10];
};

struct Pickups {
    char tipo[10];
};

struct Strings {
    char marca[20];
    char tamanho[4];
};

struct Nut {
    char tipo[10];
};

struct Guitar{
    struct Headstock headstock;
    struct Nut nut;
    struct Neck neck;
    struct Body body;
    struct Bridge bridge;
    struct Pickups pickups;
    struct Strings strings;
};
#pragma endregion

#pragma region Funcoes
void selecionarHeadStock(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Iremos comecar com o tipo de Headstock que sera utilizado na sua guitarra.\n");
    for(int i = 0; i < 3; i++){
        printf("%d: %s - %s\n", i + 1, tiposHeadstock[i], descricaoTiposHeadstock[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->headstock.tipo, tiposHeadstock[opcao - 1]);
    system("cls");
    printf("Muito bem! Seu headstock foi escolhido com sucesso. Agora escolha qual madeira constituira o headstock.\n");
    for(int i = 0; i < 4; i++){
        printf("%d: %s\n", i + 1, tiposMadeira[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->headstock.tonewood.nome, tiposMadeira[opcao - 1]);
}

void selecionarNut(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Iremos agora escolher o nut que sera utilizado na sua guitarra.\n");
    printf("Descricao: %s\n", descricaoNut);
    for(int i = 0; i < 3; i++){
        printf("%d: %s - %s\n", i + 1, tiposNut[i], descricaoTiposNut[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->nut.tipo, tiposNut[opcao - 1]);
}

void selecionarNeck(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Iremos agora escolher o neck que sera utilizado na sua guitarra.\n");
    printf("Descricao: %s\n", descricaoNeck);
    for(int i = 0; i < 4; i++){
        printf("%d: %s\n", i + 1, tiposMadeira[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->neck.tonewood.nome, tiposMadeira[opcao - 1]);
}

void selecionarBody(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Iremos agora escolher como sera construido o corpo da guitarra.\n");
    for(int i = 0; i < 3; i++){
        printf("%d: %s - %s\n", i + 1, tiposBody[i], descricaoTiposBody[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->body.tipo, tiposBody[opcao - 1]);
}

void selecionarBridge(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Escolha agora como sera a ponte da sua guitarra.\n");
    printf("Descricao: %s\n", descricaoBridge);
    for(int i = 0; i < 2; i++){
        printf("%d: %s - %s\n", i + 1, tiposBridge[i], descricaoTiposBridge[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->bridge.tipo, tiposBridge[opcao - 1]);
}

void selecionarPickups(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Captadores: \n");
    printf("Descricao: %s\n", descricaoPickups);
    for(int i = 0; i < 2; i++){
        printf("%d: %s - %s\n", i + 1, tiposPickups[i], descricaoTiposPickUps[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->pickups.tipo, tiposPickups[opcao - 1]);
}

void selecionarStrings(struct Guitar* guitarra){
    int opcao;
    system("cls");
    printf("Cordas: \n");
    printf("Qual marca de cordas voce deseja utilizar?\n");
    for(int i = 0; i < 4; i++){
        printf("%d: %s\n", i + 1, marcasStrings[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->strings.marca, marcasStrings[opcao - 1]);
    system("cls");

    printf("Excelente. Qual tamanho de cordas da %s voce deseja utilizar?\n", guitarra->strings.marca);
    for(int i = 0; i < 4; i++){
        printf("%d: %s\n", i + 1, tamanhosStrings[i]);
    }
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    strcpy(guitarra->strings.tamanho, tamanhosStrings[opcao - 1]);
    system("cls");
}
#pragma endregion

struct Guitar criarGuitarra() {
    struct Guitar guitarra;
    selecionarHeadStock(&guitarra);
    selecionarNut(&guitarra);
    selecionarNeck(&guitarra);
    selecionarBody(&guitarra);
    selecionarBridge(&guitarra);
    selecionarPickups(&guitarra);
    selecionarStrings(&guitarra);
}
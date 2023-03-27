#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pecasGuitarraManufatura.h"
#include "pagamento.h"

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
    char nome[30];
    float preco;
    struct Headstock headstock;
    struct Nut nut;
    struct Neck neck;
    struct Body body;
    struct Bridge bridge;
    struct Pickups pickups;
    struct Strings strings;
};
#pragma endregion

#pragma region Funcoes Montagem
void selecionarHeadStock(struct Guitar* guitarra){
    guitarra->preco = 0;

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
    guitarra->preco += valoresHeadstock[opcao - 1] + valoresMadeiraHeadstock[opcao - 1];
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
    guitarra->preco += valoresNut[opcao - 1];
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
    guitarra->preco += valoresMadeiraNeck[opcao - 1];
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
    
    guitarra->preco += valoresBody[opcao - 1];
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
    guitarra->preco += valoresBridges[opcao - 1];
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
    
    guitarra->preco += valoresCaptadores[opcao - 1];
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
    guitarra->preco += valoresStrings[opcao - 1];
}

#pragma endregion

void criarRelatorio(struct Guitar guitarra, int metodo, int parcelas){
    printf("Deseja gerar o relatorio da compra? \n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    int opcao;
    scanf("%d", &opcao);

    if(opcao == 1){
        srand(time(NULL));
        char luthiers[3][40] = {"Eric Klaus", "Matheus Rogerio", "Matheus Gaspar"};

        FILE *arquivo;
        arquivo = fopen(strcat(guitarra.nome, ".txt"), "w");
        fprintf(arquivo, "ERGuitars - A melhor loja de equipamentos para guitarras em Cascavel!\n");
        fprintf(arquivo, "Pedido #%d\n", rand() % 10000);
        fprintf(arquivo, "Luthier: %s\n\n", luthiers[rand() % 3]);
        fprintf(arquivo, "Visão geral: \n");
        fprintf(arquivo, "Headstock: %s\n", guitarra.headstock.tipo);
        fprintf(arquivo, "Madeira: %s\n", guitarra.headstock.tonewood.nome);
        fprintf(arquivo, "Nut: %s\n", guitarra.nut.tipo);
        fprintf(arquivo, "Neck: %s\n", guitarra.neck.tonewood.nome);
        fprintf(arquivo, "Body: %s\n", guitarra.body.tipo);
        fprintf(arquivo, "Bridge: %s\n", guitarra.bridge.tipo);
        fprintf(arquivo, "Pickups: %s\n", guitarra.pickups.tipo);
        fprintf(arquivo, "Strings: %s - %s\n", guitarra.strings.marca, guitarra.strings.tamanho);
        fprintf(arquivo, "Preço: R$%.2f\n", guitarra.preco);
        if(metodo == 1){
            fprintf(arquivo, "Método de Pagamento: Boleto parcelado, %dx de R$%.2f\n\n", parcelas, guitarra.preco / parcelas);
        } else if(metodo == 2){ 
            fprintf(arquivo, "Método de Pagamento: R$%.2f a vista por pix\n\n", guitarra.preco * 0.9);
        } else if(metodo == 3){
            fprintf(arquivo, "Método de Pagamento: R$%.2f a vista por pix\n\n", guitarra.preco);
        }
        fprintf(arquivo, "Obrigado pela escolha! Aproveite o pedido!\n");
        fprintf(arquivo, "ERGGuitars - Cascavel\n");
        fprintf(arquivo, "Telefone 4002-8922\n");
        fclose(arquivo);
    } else {
        printf("Obrigado pela escolha! Aproveite o pedido!\n");
    }
}

struct Guitar criarGuitarra() {
    struct Guitar guitarra;

    printf("Qual sera o nome da sua guitarra customizada?\n");
    scanf("%s", guitarra.nome);
    selecionarHeadStock(&guitarra);
    selecionarNut(&guitarra);
    selecionarNeck(&guitarra);
    selecionarBody(&guitarra);
    selecionarBridge(&guitarra);
    selecionarPickups(&guitarra);
    selecionarStrings(&guitarra);
    int parcelas;
    int metodoPagamento = pagar(guitarra.preco, &parcelas);
    criarRelatorio(guitarra, metodoPagamento, parcelas);

    //system("cls");
    printf("Parabens pela sua guitarra! Ela sera entregue em 7 dias!\n");
}
#include <stdio.h>
#include <stdlib.h>

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
    char descricao[200] = "O neck da guitarra consiste em um pedaco de madeira localizado entre o Headstock e o Body que contrapoe a tensao gerada pelas cordas e estabiliza a precisao da afinacao."; 
    struct Tonewood tonewood;
};

struct Body {
    char tipo[15];
};

struct Bridge {
    char descricao[200] = "A ponte da guitarra e responsavel por sustentar as cordas e transmitir a vibracao gerada pelas cordas para o corpo da guitarra.";
    char tipo[10];
};

struct Pickups {
    char descricao[200] = "Os pickups sao responsaveis por captar a vibracao das cordas e transforma-la em um sinal eletrico que sera amplificado pelo amplificador.";
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
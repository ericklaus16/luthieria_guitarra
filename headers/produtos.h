// Headstock
char tiposHeadstock[3][15] = {"Straight", "Tilted-back", "Scarf"};
float valoresHeadstock[3] = {200, 1000, 1500};
char descricaoTiposHeadstock[3][300] = {
    "Esse tipo de Headstock nao possui nenhum tipo de angulacao, seu design simples resulta em um preco menor.", 
    "Esse tipo de Headstock possui uma angulacao consideravel com o braco da guitarra, devido a angulacao as cordas estao menos propensas a desafinar.", 
    "Esse tipo de Headstock possui a mesma angulacao que o Tilted-back, mas, possui uma estabilidade maior e um timbre melhor das cordas."
};

char tiposMadeira[4][20] = {"Maple", "Rosewood", "Ebony", "Walnut"};
float valoresMadeiraHeadstock[4] = {150, 300, 800, 150};

// Neck
char descricaoNeck[300] = "O neck da guitarra, um dos aspectos visuais mais importantes da guitarra, consiste em um pedaco de madeira localizado entre o Headstock e o Body que contrapoe a tensao gerada pelas cordas e estabiliza a precisao da afinacao.";   
float valoresMadeiraNeck[4] = {600, 1500, 3000, 600};

// Nut
char descricaoNut[200] = "O nut, tambem chamado de 'pestana', eh responsavel pelo ponto de apoio das cordas que 'chegam' nas tarraxas passando sobre a escala do instrumento, partindo da ponte.";
char tiposNut[3][10] = {"Metal", "Plastico", "Grafite"};
char descricaoTiposNut[3][200] = {
    "O tipo Metal tem maior durabilidade, alem de prover um som bonito e limpo. Por causa disso, acabam sendo mais caros que os outros tipos.", 
    "O tipo Plastico tem menor custo de fabricacao, sendo comumente instalado em guitarras de entrada. O plastico carece de desempenho devido suas propriedades menos solidas", 
    "O tipo Grafite oferece uma estabilidade impecavel para a afinacao das cordas, com isso, faz um excelente trabalho em guitarras com Whammy bar sem a ponte fixa."
};
float valoresNut[3] = {300, 125, 325};

// Body
char tiposBody[3][15] = {"Solid", "Semi-Hollow", "Hollow"};
char descricaoTiposBody[3][300] = {
    "O corpo do tipo Solid fornece ao instrumento um sustain um pouco mais longo do que as guitarras com corpo Hollow. Soam muito mais pesadas quando tocadas com amplificador.", 
    "O corpo do tipo Semi-Hollow fornece ao instrumento um timbre melhor e pode ser usado para tocar qualquer tipo de musica que nao necessite de grandes quantidades de ganho.", 
    "O corpo do tipo Hollow apesar de possuir um timbre de qualidade impressionante, tem uma ressonancia que desaponta a expectativa de muitos guitarristas."
};
float valoresBody[3] = {800, 1500, 2500};


// Strings
char marcasStrings[4][20] = {"Ernie Ball", "D'Addario", "Elixir", "Solez"};
char tamanhosStrings[4][4] = {"010", "011", "012", "013"};
float valoresStrings[4] = {50, 60, 120, 45};

// Bridge
char tiposBridge[2][10] = {"Fixed", "Tremolo"};
char descricaoBridge[200] = "A ponte da guitarra e responsavel por sustentar as cordas e transmitir a vibracao gerada pelas cordas para o corpo da guitarra.";
char descricaoTiposBridge[2][200] = {"A ponte fixa eh presa ao corpo da guitarra, com isso, eh possivel obter efeitos de vibracao diferentes na guitarra. Alem disso, a ponte fixa torna dificil as cordas desafinarem. ", "A ponte do tipo Tremolo permite que o guitarrista literalmente consiga reproduzir 'tremidas' no som."};
float valoresBridges[2] = {400, 300};

// Pickups
char descricaoPickups[200] = "Os pickups sao responsaveis por captar a vibracao das cordas e transforma-la em um sinal eletrico que sera amplificado pelo amplificador.";
char tiposPickups[2][20] = {"Single-Coil", "Humbucker"};
char descricaoTiposPickUps[2][200] = {"O tipo Single-Coil eh o mais comum em guitarras, ele possui um timbre mais quente e um sustain mais curto.", "O tipo Humbucker eh o mais comum em guitarras de metal, ele possui um timbre mais agudo e um sustain mais longo."};
float valoresCaptadores[3] = {200, 300};
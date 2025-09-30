#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

struct Carta {
    char estado;
    char codigo[MAX_STRING];
    char nome[MAX_STRING];
    int populacao;
    float area;
    float pib;
    int turismo;
    float densidade;
    float pibPerCapita;
};

void removerQuebraDeLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void preencherCarta(struct Carta *carta, int numero) {
    printf("Vamos preencher a carta %d\n", numero + 1);

    printf("Insira uma letra de 'A' a 'H' para representar seu estado: ");
    scanf(" %c", &carta->estado);
    getchar();

    printf("Insira o código da carta do seu estado: ");
    fgets(carta->codigo, MAX_STRING, stdin);
    removerQuebraDeLinha(carta->codigo);

    printf("Insira o nome da cidade do seu estado: ");
    fgets(carta->nome, MAX_STRING, stdin);
    removerQuebraDeLinha(carta->nome);

    printf("Insira a população da cidade do seu estado: ");
    scanf("%d", &carta->populacao);

    printf("Insira a área da cidade do seu estado: ");
    scanf("%f", &carta->area);

    printf("Insira o PIB da cidade do seu estado (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Insira o número de pontos turísticos da cidade do seu estado: ");
    scanf("%d", &carta->turismo);
    getchar();


    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
}

void mostrarCarta(const struct Carta *carta) {
    printf("\n=== Carta ===\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %c%s\n", carta->estado, carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade);
    printf("PIB per Capita: %.2f reais\n", carta->pibPerCapita);
}

int main() {
    printf("Bem vindo ao Super Trunfo de estados brasileiros\n");
    printf("Você terá que inserir dados de duas cartas para jogar\n");

    struct Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        preencherCarta(&cartas[i], i);
    }

    for (int i = 0; i < 2; i++) {
        mostrarCarta(&cartas[i]);
    }

    return 0;
}

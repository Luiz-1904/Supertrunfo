#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

struct Carta {
    char estado;
    char codigo[MAX_STRING];
    char nome[MAX_STRING];
    unsigned long int populacao;
    float area;
    float pib;
    int turismo;
    float densidade;
    float pibPerCapita;
    float superPoder;
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
    scanf("%lu", &carta->populacao);

    printf("Insira a área da cidade do seu estado: ");
    scanf("%f", &carta->area);

    printf("Insira o PIB da cidade do seu estado (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Insira o número de pontos turísticos da cidade do seu estado: ");
    scanf("%d", &carta->turismo);
    getchar();

    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->turismo + carta->pibPerCapita + (1 / carta->densidade);
}

void mostrarCarta(const struct Carta *carta) {
    printf("\n=== Carta ===\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %c%s\n", carta->estado, carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade);
    printf("PIB per Capita: %.2f reais\n", carta->pibPerCapita);
    printf("Super Poder: %.2f\n", carta->superPoder);
}

void compararCartas(const struct Carta *carta1, const struct Carta *carta2) {
    printf("\n=== Comparação de Cartas ===\n");

    printf("População: Carta %d venceu (%d)\n", (carta1->populacao > carta2->populacao) ? 1 : 2, carta1->populacao > carta2->populacao);
    printf("Área: Carta %d venceu (%d)\n", (carta1->area > carta2->area) ? 1 : 2, carta1->area > carta2->area);
    printf("PIB: Carta %d venceu (%d)\n", (carta1->pib > carta2->pib) ? 1 : 2, carta1->pib > carta2->pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (carta1->turismo > carta2->turismo) ? 1 : 2, carta1->turismo > carta2->turismo);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (carta1->densidade < carta2->densidade) ? 1 : 2, carta1->densidade < carta2->densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (carta1->pibPerCapita > carta2->pibPerCapita) ? 1 : 2, carta1->pibPerCapita > carta2->pibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", (carta1->superPoder > carta2->superPoder) ? 1 : 2, carta1->superPoder > carta2->superPoder);
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

    compararCartas(&cartas[0], &cartas[1]);

    return 0;
}

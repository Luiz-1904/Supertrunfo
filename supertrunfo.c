#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

struct Carta {
    char estado[3];
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
    printf("\nVamos preencher a carta %d\n", numero + 1);

    printf("Insira a sigla do estado (2 letras): ");
    fgets(carta->estado, 3, stdin);
    getchar();

    printf("Insira o código da carta: ");
    fgets(carta->codigo, MAX_STRING, stdin);
    removerQuebraDeLinha(carta->codigo);

    printf("Insira o nome da cidade: ");
    fgets(carta->nome, MAX_STRING, stdin);
    removerQuebraDeLinha(carta->nome);

    printf("Insira a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Insira a área da cidade (km²): ");
    scanf("%f", &carta->area);

    printf("Insira o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Insira o número de pontos turísticos: ");
    scanf("%d", &carta->turismo);
    getchar();

    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
}

void compararCartas(const struct Carta *carta1, const struct Carta *carta2) {
    printf("\n=== Comparação de Cartas ===\n");
    
    int atributoEscolhido = 1;
    
    if (atributoEscolhido == 1) {
        printf("Atributo: População\n");
        printf("Carta 1 - %s (%s): %d\n", carta1->nome, carta1->estado, carta1->populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2->nome, carta2->estado, carta2->populacao);
        
        if (carta1->populacao > carta2->populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nome);
        } else if (carta2->populacao > carta1->populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

void mostrarCarta(const struct Carta *carta) {
    printf("\n=== Carta ===\n");
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
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

    compararCartas(&cartas[0], &cartas[1]);

    return 0;
}
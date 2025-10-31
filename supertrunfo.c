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

float obterValorAtributo(const struct Carta *carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->turismo;
        case 5: return carta->densidade;
        case 6: return carta->pibPerCapita;
        default: return 0.0;
    }
}

float obterValorAtributoParaSoma(const struct Carta *carta, int atributo) {
    if (atributo == 5) {
        return 1.0f / carta->densidade;
    }
    return obterValorAtributo(carta, atributo);
}

const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

void mostrarMenu(int excluir) {
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    for (int i = 1; i <= 6; i++) {
        if (i != excluir) {
            printf("%d. %s\n", i, nomeAtributo(i));
        }
    }
}

int compararAtributoIndividual(const struct Carta *carta1, const struct Carta *carta2, int atributo) {
    float valor1 = obterValorAtributo(carta1, atributo);
    float valor2 = obterValorAtributo(carta2, atributo);
    
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    } else {
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
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
    int atributo1, atributo2;

    for (int i = 0; i < 2; i++) {
        preencherCarta(&cartas[i], i);
    }

    for (int i = 0; i < 2; i++) {
        mostrarCarta(&cartas[i]);
    }

    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    
    do {
        printf("\nEscolha o primeiro atributo:\n");
        mostrarMenu(0);
        printf("Digite sua opção (1-6): ");
        scanf("%d", &atributo1);
        
        if (atributo1 < 1 || atributo1 > 6) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }
        
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        mostrarMenu(atributo1);
        printf("Digite sua opção: ");
        scanf("%d", &atributo2);
        
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Opção inválida! O segundo atributo deve ser diferente do primeiro.\n");
            continue;
        }
        
        break;
    } while (1);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s (%s)\n", cartas[0].nome, cartas[0].estado);
    printf("País 2: %s (%s)\n", cartas[1].nome, cartas[1].estado);
    printf("Atributos escolhidos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    
    printf("\n--- Valores dos Atributos ---\n");
    printf("%s:\n", nomeAtributo(atributo1));
    printf("  %s: ", cartas[0].nome);
    if (atributo1 == 1) printf("%d", cartas[0].populacao);
    else if (atributo1 == 2) printf("%.2f km²", cartas[0].area);
    else if (atributo1 == 3) printf("%.2f bilhões", cartas[0].pib);
    else if (atributo1 == 4) printf("%d", cartas[0].turismo);
    else if (atributo1 == 5) printf("%.2f hab/km²", cartas[0].densidade);
    else if (atributo1 == 6) printf("%.2f", cartas[0].pibPerCapita);
    printf("\n");
    
    printf("  %s: ", cartas[1].nome);
    if (atributo1 == 1) printf("%d", cartas[1].populacao);
    else if (atributo1 == 2) printf("%.2f km²", cartas[1].area);
    else if (atributo1 == 3) printf("%.2f bilhões", cartas[1].pib);
    else if (atributo1 == 4) printf("%d", cartas[1].turismo);
    else if (atributo1 == 5) printf("%.2f hab/km²", cartas[1].densidade);
    else if (atributo1 == 6) printf("%.2f", cartas[1].pibPerCapita);
    printf("\n");
    
    printf("%s:\n", nomeAtributo(atributo2));
    printf("  %s: ", cartas[0].nome);
    if (atributo2 == 1) printf("%d", cartas[0].populacao);
    else if (atributo2 == 2) printf("%.2f km²", cartas[0].area);
    else if (atributo2 == 3) printf("%.2f bilhões", cartas[0].pib);
    else if (atributo2 == 4) printf("%d", cartas[0].turismo);
    else if (atributo2 == 5) printf("%.2f hab/km²", cartas[0].densidade);
    else if (atributo2 == 6) printf("%.2f", cartas[0].pibPerCapita);
    printf("\n");
    
    printf("  %s: ", cartas[1].nome);
    if (atributo2 == 1) printf("%d", cartas[1].populacao);
    else if (atributo2 == 2) printf("%.2f km²", cartas[1].area);
    else if (atributo2 == 3) printf("%.2f bilhões", cartas[1].pib);
    else if (atributo2 == 4) printf("%d", cartas[1].turismo);
    else if (atributo2 == 5) printf("%.2f hab/km²", cartas[1].densidade);
    else if (atributo2 == 6) printf("%.2f", cartas[1].pibPerCapita);
    printf("\n");

    int resultado1 = compararAtributoIndividual(&cartas[0], &cartas[1], atributo1);
    int resultado2 = compararAtributoIndividual(&cartas[0], &cartas[1], atributo2);
    
    printf("\n--- Comparação Individual ---\n");
    printf("%s: %s venceu\n", nomeAtributo(atributo1), 
           (resultado1 == 1) ? cartas[0].nome : (resultado1 == 2) ? cartas[1].nome : "Empate");
    printf("%s: %s venceu\n", nomeAtributo(atributo2), 
           (resultado2 == 1) ? cartas[0].nome : (resultado2 == 2) ? cartas[1].nome : "Empate");

    float soma1 = obterValorAtributoParaSoma(&cartas[0], atributo1) + 
                  obterValorAtributoParaSoma(&cartas[0], atributo2);
    float soma2 = obterValorAtributoParaSoma(&cartas[1], atributo1) + 
                  obterValorAtributoParaSoma(&cartas[1], atributo2);
    
    printf("\n--- Soma dos Atributos ---\n");
    printf("%s: %.2f\n", cartas[0].nome, soma1);
    printf("%s: %.2f\n", cartas[1].nome, soma2);
    
    printf("\n--- RESULTADO FINAL ---\n");
    if (soma1 > soma2) {
        printf("Vencedor: %s (%s)\n", cartas[0].nome, cartas[0].estado);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s (%s)\n", cartas[1].nome, cartas[1].estado);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
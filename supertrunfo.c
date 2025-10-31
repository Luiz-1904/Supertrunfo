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

void mostrarMenu() {
    printf("\n=== MENU SUPER TRUNFO ===\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("6. Sair\n");
    printf("Digite sua opção (1-6): ");
}

void compararCartas(const struct Carta *carta1, const struct Carta *carta2, int opcao) {
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s (%s)\n", carta1->nome, carta1->estado);
    printf("País 2: %s (%s)\n", carta2->nome, carta2->estado);
    
    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1->nome, carta1->populacao);
            printf("%s: %d habitantes\n", carta2->nome, carta2->populacao);
            
            if (carta1->populacao > carta2->populacao) {
                printf("Resultado: %s venceu!\n", carta1->nome);
            } else if (carta2->populacao > carta1->populacao) {
                printf("Resultado: %s venceu!\n", carta2->nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1->nome, carta1->area);
            printf("%s: %.2f km²\n", carta2->nome, carta2->area);
            
            if (carta1->area > carta2->area) {
                printf("Resultado: %s venceu!\n", carta1->nome);
            } else if (carta2->area > carta1->area) {
                printf("Resultado: %s venceu!\n", carta2->nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1->nome, carta1->pib);
            printf("%s: %.2f bilhões\n", carta2->nome, carta2->pib);
            
            if (carta1->pib > carta2->pib) {
                printf("Resultado: %s venceu!\n", carta1->nome);
            } else if (carta2->pib > carta1->pib) {
                printf("Resultado: %s venceu!\n", carta2->nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1->nome, carta1->turismo);
            printf("%s: %d pontos\n", carta2->nome, carta2->turismo);
            
            if (carta1->turismo > carta2->turismo) {
                printf("Resultado: %s venceu!\n", carta1->nome);
            } else if (carta2->turismo > carta1->turismo) {
                printf("Resultado: %s venceu!\n", carta2->nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 5: // Densidade Demográfica
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1->nome, carta1->densidade);
            printf("%s: %.2f hab/km²\n", carta2->nome, carta2->densidade);
            
            // Para densidade, menor valor vence
            if (carta1->densidade < carta2->densidade) {
                printf("Resultado: %s venceu!\n", carta1->nome);
            } else if (carta2->densidade < carta1->densidade) {
                printf("Resultado: %s venceu!\n", carta2->nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
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
    int opcao;

    for (int i = 0; i < 2; i++) {
        preencherCarta(&cartas[i], i);
    }

    for (int i = 0; i < 2; i++) {
        mostrarCarta(&cartas[i]);
    }

    do {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao >= 1 && opcao <= 5) {
            compararCartas(&cartas[0], &cartas[1], opcao);
        } else if (opcao == 6) {
            printf("Obrigado por jogar Super Trunfo!\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 6) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
        
    } while (opcao != 6);

    return 0;
}
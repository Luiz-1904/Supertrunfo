#include <iostream>
#include <vector>
#include <limits>

struct Carta{
    char estado;
    std::string codigo;
    std::string nome;
    int população;
    float área;
    float pib;
    int turismo;
    float densidade;
    float pibPerCapita;
    float superPoder;
};

void preencherCarta(Carta &carta, int numero){
    std::cout << " \n Vamos preencher a carta " << numero+1 << "\n";
    std::cout << " \n Insira uma letra de 'A' a 'H' para representar seu estado: ";
    std::cin >> carta.estado;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n Insira o código da carta do seu estado: ";
    std::getline(std::cin, carta.codigo);

    std::cout << "\n Insira o nome da cidade do seu estado: ";
    std::getline(std::cin, carta.nome);

    std::cout << "\n Insira a população da cidade do seu estado: ";
    std::cin >> carta.população;

    std::cout << "\n Insira a área da cidade do seu estado: ";
    std::cin >> carta.área;

    std::cout << "\n Insira o PIB da cidade do seu estado: ";
    std::cin >> carta.pib;

    std::cout << "\n Insira o número de pontos turísticos da cidade do seu estado: ";
    std::cin >> carta.turismo;

    carta.densidade = carta.população / carta.área;
    carta.pibPerCapita = carta.pib * 1e9 / carta.população;
    carta.superPoder = carta.população
        + carta.área
        + carta.pib
        + carta.turismo
        + carta.pibPerCapita
        + (1 / carta.densidade);
}

void mostrarCarta(const Carta &carta){
    std::cout << "\n=== Carta ===\n";
    std::cout << "Estado: " << carta.estado << "\n";
    std::cout << "Código: " << carta.estado << carta.codigo << "\n";
    std::cout << "Nome: " << carta.nome << "\n";
    std::cout << "População: " << carta.população << "\n";
    std::cout << "Área: " << carta.área << " km²\n";
    std::cout << "PIB: " << carta.pib << " bilhões de reais\n";
    std::cout << "Número de Pontos Turísticos: " << carta.turismo << "\n";
    std::cout << "Densidade Populacional: " << carta.densidade << " hab/km²\n";
    std::cout << "PIB per Capita: " << carta.pibPerCapita << "\n";
}

void compararCartas(const Carta& carta1, const Carta& carta2) {
    std::cout << "\n=== Comparação de Cartas ===";

    // População (maior vence)
    bool popVence = carta1.população > carta2.população;
    std::cout << "\nPopulação: Carta " << (popVence ? "1" : "2") << " venceu (" << popVence << ")";

    // Área (maior vence)
    bool areaVence = carta1.área > carta2.área;
    std::cout << "\nÁrea: Carta " << (areaVence ? "1" : "2") << " venceu (" << areaVence << ")";

    // PIB (maior vence)
    bool pibVence = carta1.pib > carta2.pib;
    std::cout << "\nPIB: Carta " << (pibVence ? "1" : "2") << " venceu (" << pibVence << ")";

    // Pontos Turísticos (maior vence)
    bool turismoVence = carta1.turismo > carta2.turismo;
    std::cout << "\nPontos Turísticos: Carta " << (turismoVence ? "1" : "2") << " venceu (" << turismoVence << ")";

    // Densidade Populacional (MENOR vence)
    bool densidadeVence = carta1.densidade < carta2.densidade;
    std::cout << "\nDensidade Populacional: Carta " << (densidadeVence ? "1" : "2") << " venceu (" << densidadeVence << ")";

    // PIB per Capita (maior vence)
    bool pibPerCapitaVence = carta1.pibPerCapita > carta2.pibPerCapita;
    std::cout << "\nPIB per Capita: Carta " << (pibPerCapitaVence ? "1" : "2") << " venceu (" << pibPerCapitaVence << ")";

    // Super Poder (maior vence)
    bool superPoderVence = carta1.superPoder > carta2.superPoder;
    std::cout << "\nSuper Poder: Carta " << (superPoderVence ? "1" : "2") << " venceu (" << superPoderVence << ")";
}

int main() {
     std::cout << "Bem vindo ao Super Trunfo de estados brasileiros \n"
    << "Você terá que inserir dados de duas cartas para jogar\n";
    std::vector<Carta> cartas(2);

    for (int i = 0; i < 2; i++) {
        preencherCarta(cartas[i], i);
    }

    for(auto &carta : cartas){
        mostrarCarta(carta);
    }

    compararCartas(cartas[0], cartas[1]);
    return 0;
}

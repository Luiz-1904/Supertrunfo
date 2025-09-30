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
    return 0;
}

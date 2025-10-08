#include <iostream>
#include <random> // Para a geração moderna de números aleatórios em C++
#include <limits> // Usado para limpar o buffer de entrada em caso de erro

int main() {
    // --- Configuração do Gerador de Números Aleatórios ---
    // 1. Obter um "seed" (semente) não determinístico do hardware do sistema.
    std::random_device rd; 
    // 2. Criar uma instância do motor de geração de números aleatórios Mersenne Twister, semeado com rd().
    std::mt19937 gen(rd());
    // 3. Definir a distribuição que queremos (um número inteiro uniforme entre 1 e 100).
    std::uniform_int_distribution<> distrib(1, 100);

    // Gera o número secreto que o jogador deve adivinhar
    int numero_secreto = distrib(gen);
    
    int palpite = 0;
    int tentativas = 0;

    // --- Início do Jogo ---
    std::cout << "*****************************************" << std::endl;
    std::cout << "* Bem-vindo ao Jogo de Adivinhacao! *" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "Eu pensei em um numero entre 1 e 100. Tente adivinhar qual e!" << std::endl;
    std::cout << std::endl;

    // --- Loop Principal do Jogo ---
    // O loop continua enquanto o palpite do jogador for diferente do número secreto.
    do {
        std::cout << "Qual e o seu palpite? ";
        std::cin >> palpite;

        // Verificação de erro: Checa se a entrada do usuário foi um número válido.
        if (std::cin.fail()) {
            std::cout << "Erro: Por favor, digite um numero valido." << std::endl;
            std::cin.clear(); // Limpa o estado de erro do std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a entrada inválida
            continue; // Pula para a próxima iteração do loop
        }

        tentativas++; // Incrementa o contador de tentativas

        if (palpite > numero_secreto) {
            std::cout << "Seu palpite foi muito alto!" << std::endl;
        } else if (palpite < numero_secreto) {
            std::cout << "Seu palpite foi muito baixo!" << std::endl;
        } else {
            std::cout << "Parabens! Voce acertou o numero!" << std::endl;
            std::cout << "Voce precisou de " << tentativas << " tentativas." << std::endl;
        }
        
    } while (palpite != numero_secreto);

    return 0;
}

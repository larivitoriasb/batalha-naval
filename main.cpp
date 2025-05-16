#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAMANHO = 5;

// Função pra inicializar o tabuleiro com água (~)
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

// Função pra mostrar o tabuleiro no terminal
void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    cout << "  ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < TAMANHO; i++) {
        cout << i << " ";
        for (int j = 0; j < TAMANHO; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    char tabuleiroJogador[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiroJogador);

    int linhaAlvo = rand() % TAMANHO;
    int colunaAlvo = rand() % TAMANHO;

    int tentativas = 5;

cout << "Bem-vind0 (a) ao Batalha Naval! 🛳️💥\n";
    cout << "Você tem " << tentativas << " tentativas para afundar o navio inimigo escondido!\n\n";

    while (tentativas > 0) {
        mostrarTabuleiro(tabuleiroJogador);

        int linha, coluna;
        cout << "\nDigite a linha (0 a " << TAMANHO - 1 << "): ";
        cin >> linha;
        cout << "Digite a coluna (0 a " << TAMANHO - 1 << "): ";
        cin >> coluna;

        if (linha == linhaAlvo && coluna == colunaAlvo) {
            cout << "\n💣 BOOOOM! Você acertou o navio! Parabéns, capitã!\n";
            tabuleiroJogador[linha][coluna] = 'X';
            break;
        } else {
            cout << "\nSplash... você acertou a água. Tente de novo!\n";
            tabuleiroJogador[linha][coluna] = 'O';
            tentativas--;
        }
    }

    if (tentativas == 0) {
        cout << "\n😭 Fim de jogo! O navio estava em (" << linhaAlvo << ", " << colunaAlvo << ").\n";
    }

    mostrarTabuleiro(tabuleiroJogador);
    return 0;
}

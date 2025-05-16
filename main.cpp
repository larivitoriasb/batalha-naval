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

// Função pra mostrar o tabuleiro com letras nas linhas
void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    cout << "  ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < TAMANHO; i++) {
        cout << char('A' + i) << " ";  // A, B, C, D, E
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

    cout << "Bem-vindo (a) ao Batalha Naval!\n";
    cout << "Voce tem " << tentativas << " tentativas para afundar o navio inimigo escondido!\n\n";

    while (tentativas > 0) {
        mostrarTabuleiro(tabuleiroJogador);

        char linhaLetra;
        int linha, coluna;

        cout << "\nDigite a linha (A a E): ";
        cin >> linhaLetra;
        linhaLetra = toupper(linhaLetra); // Aceita 'a' ou 'A'
        linha = linhaLetra - 'A';

        cout << "Digite a coluna (0 a " << TAMANHO - 1 << "): ";
        cin >> coluna;

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            cout << "\nCoordenada invalida! Tenta de novo, comandante!\n";
            continue;
        }

        if (linha == linhaAlvo && coluna == colunaAlvo) {
            cout << "\n💥 BOOOOM! Voce acertou o navio! Parabens, capitao!\n";
            tabuleiroJogador[linha][coluna] = 'X';
            break;
        } else {
            cout << "\n🌊 Splash... voce acertou a agua. Tente de novo!\n";
            tabuleiroJogador[linha][coluna] = 'O';
            tentativas--;
        }
    }

    if (tentativas == 0) {
        cout << "\nFim de jogo! O navio estava em (" << char('A' + linhaAlvo) << ", " << colunaAlvo << ").\n";
    }

    mostrarTabuleiro(tabuleiroJogador);
    return 0;
}

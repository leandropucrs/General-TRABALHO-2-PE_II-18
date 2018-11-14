#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;


class jogador {
public:
string nome;
int pontos;
int rodada;

jogador (string nome, int pontos, int rodada){
	this->nome = nome;
	this->pontos = pontos;
	this->rodada = rodada;
}};

void jogadores (vector<jogador>& jogo) {
	string nome;
	int pontos;
	int rodada;

	ifstream jogador;
	
	jogador.open("jogo.txt");

if ( ! jogador.is_open() ) {
        cerr << "Erro ao abrir arquivo de entrada!" << endl;
        exit(-1);
    }

    jogador >> nome;
    jogador >> pontos;
    jogador >> rodada;

while (jogador.good()) {
	jogador c(nome,pontos,rodada);
	jogo.pushback(c);
 jogador >> nome;
    jogador >> pontos;
    jogador >> rodada;
}


	jogador.close();
}

void mostrar(vector<jogador> jogo) {
    for(int i = 0; i < jogo.size(); i++) {
        cout << jogo[i].nome << ", " << jogo[i].pontos << ", " << jogo[i].rodada << endl;
    }
}

int main(){

int jogadas, jogadas1, jogadas2, jogadas3, jogadas4;
int dado1, dado2, dado3, dado4, dado5;
int jogador1, jogador2, jogador3, jogador4;
int pontos;



srand ( time(NULL) );
dado1 = rand() % 6;
dado2 = rand() % 6;
dado3 = rand() % 6;
dado4 = rand() % 6;
dado5 = rand() % 6;


cout<< "  "<< dado1<<endl;
cout<< "  "<< dado2<<endl;
cout<< "  "<< dado3<<endl;
cout<< "  "<< dado4<<endl;
cout<< "  "<< dado5<<endl;

vector<jogador> jogadores;

mostrar(jogadores);


}

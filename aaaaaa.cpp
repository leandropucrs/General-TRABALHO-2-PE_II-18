#include <iostream>
#include <ctime>		
#include <string>		
#include <sstream>		
#include <vector>		
#include <algorithm>	

using namespace std;

//const int pq é só leitura
const int MAX_DADOS = 5;
const int MAX_TURNOS = 13;
const int MAX_JOG = 8;
const int PONTOS = 14; 

// Função Bem-vindo
void bemvindo(void){
	cout << "=============================================" << endl;
	cout << "==-----------------------------------------==" << endl;
	cout << "=|\t         GENERAL                   |=" << endl;
	cout << "==-----------------------------------------==" << endl;
	cout << "=============================================" << endl;


}

// Número de jogadores 
int getNum_jogadores(void){
	int num;
	bool valido = false;

	// Loop até um número valido de jogadores 
	do{
		cout << "Entre com o número de jogadores: ";
		cin >> num;

		// Testa se "num" é válido 
		if (cin.good() && num > 0){
			valido = true;
		}
		else {
			// Invalido "num". Reseta e deixa em branco (buffer) 
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora o q tava no "cin"
			cout << "Número inválido! Tente novamente..." << endl << endl;
		}
	} while (!valido);

	return num;
}

// Pega nome com até 7 caracteres 
string getNome(int i){
	string nom;
	bool NomeValido = false;
	
		// Loop até nome válido ser digitado 
		do{
			cout << "Nome do Jogador " << i + 1 << ": ";
			cin >> nom;

			// corta nome para 7 caracteres 
			if (nom.length()> 7)
				nom.erase(nom.begin() + 7, nom.end());

			// Testa "nom" 
			if (cin.good() && nom != ""){

				// Se o nome foi aceito, sai do loop 
				NomeValido = true;
			}
			else {

				// Se o nome é inválido, reseta e limpa o buffer 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//Mesmo esquema de antes pra limpar o "cin"
				cout << "Nome inválido! Tente novamente..." << endl << endl;
			}
		} while (!NomeValido);        // loop se nome não é válido 


	return nom;
}

// Função Girar is dados. Gera valores para os 5 dados,
//permitindo que o jogador gire novamente de 1 a 5 dados até 2x
void GiraDado(int dado[])
{
	const int MAX_TURNOS = 3;

	// Gera os valores iniciais do dado
	cout << "Primeiro giro: ";
	for (int i = 0; i < MAX_DADOS; ++i)
	{
		dado[i] = rand() % 6 + 1;
		cout << dado[i] << " ";
	}

	// Determina se algum dado deve ser rolado novamente
	for (int turno = 1; turno < MAX_TURNOS; ++turno)
	{
		cout << "\n Você deseja girar algum dado novamente? (s/n)" << endl;
		char giro_novo; cin >> giro_novo;

		// Determina qual dado deve girar novamente
		if (toupper(gira_novo) == 'S')//converte minuscula em maiuscula "toupper"
		{
			for (int i = 0; i < MAX_DADOS; ++i)
			{
				cout << "Girar novamente " << i + 1 << " [" << dado[i] << "]? (s/n)";
				char giro_novo; cin >> giro_novo;

				// Girar novamente dado
				if (toupper(gira_novo) == 'S') dado[i] = rand() % 6 + 1;
			}

			// mostra o novo giro de dado 
			cout << "\n Novo giro: ";
			for (int i = 0; i < MAX_DADOS; ++i)
				cout << dado[i] << " ";
		}

		// Se não é solicitado girar novamente, termina o turno
		else turn = MAX_TURNOS;
	}
}

// Função pontuação. seleciona a categoria de pontos e determina de acordo com os dados
void pontuacao(int dado[], vector<vector<int>> &tabela, int jogador){

	// Verifica se o ponto de GENERAL é apĺicavél 
	bool general = false;
	if (tabela[jogador][11] >= 50){
		int t[6];
		for (int i = 0; i < 6; ++i){
			t[i] = count(dado, dado + MAX_DADOS, i + 1);
			if (t[i] == 5){
				general = true;
			}
		}
	}

	// Categorias de pontos 
	string category[13] = { "Uns", "Dois", "Três", "Quatros", "Cincos", "Seis",
		"Trinca", "Quadra", "Full House", "Sequência Menor", "Sequência Maior", "General", "Jogada X" };

	// Seleção da pontuação. Repete se a pontuação selecionada foi usada ou é inválida
	bool repete;
	do{
		
		repete = false;
	
		// Mostra pontos do dado 
		cout << "\n Pontuação do giro: ";
		for (int i = 0; i < MAX_DADOS; ++i)
			cout << dado[i] << " ";

		// Remove pontuação usada da tabela 
		for (int i = 0; i < 13; ++i){
			if (tabela[jogador][i] != 0)
				categoria[i] = "----";
		}


		// Mostra opções na tabela
		cout << "\n Selecione uma opção para pontuação:" << endl;
		cout << "1. " << categoria[0] << " \t 7. " << categoria[6] << endl;
		cout << "2. " << categoria[1] << " \t 8. " << categoria[7] << endl;
		cout << "3. " << categoria[2] << " \t 9. " << categoria[8] << endl;
		cout << "4. " << categoria[3] << " \t 10. " << categoria[9] << endl;
		cout << "5. " << categoria[4] << " \t 11. " << categoria[10] << endl;
		cout << "6. " << categoria[5] << " \t 12. " << categoria[11] << endl;
		cout << "\t\t 13. " << categoria[12] << endl;
		cout << "Selecione:";
		int op;
		cin >> op;
		cin.ignore();
		cout << op;

		// Opções, "switch" de casos 
		switch (op){

			case 1:		// Uns 

				// Verifica se espaço ta vazio 
				if (tabela[jogador][0] == 0){
					int tponto = 0;

					// Calcula pontos que vão ser inseridos 
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 1)
							tponto += dado[i];
					}

					// coloca ponto na tabela do jogado
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][0] = tponto;
					break;
				}

				// Categoria já foi usada, sai e manda escolher outra
				else if (tabela[jogador][0] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}
		
			case 2:		//Dois 

				// Verifica se espaço ta vazio
				if (tabela[jogador][1] == 0){
					int tponto = 0;

					// Calcula pontos que vão ser inseridos
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 2)
							tponto += dado[i];
					}

					// coloca ponto na tabela do jogado
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][1] = tponto;
					break;
				}

				// Categoria já foi usada, sai e manda escolher outra
				else if (tabela[jogador][1] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 3:		// Três 

				// Verifica se espaço ta vazio
				if (tabela[jogador][2] == 0){
					int tponto = 0;

					// Calcula pontos que vão ser inseridos
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 3)
							tponto += dado[i];
					}

					// coloca ponto na tabela do jogado
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][2] = tponto;
					break;
				}

				// Categoria já foi usada, sai e manda escolher outra
				else if (tabela[jogador][2] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 4:		/* Quatros */

				// Verifica se espaço ta vazio
				if (tabela[jogador][3] == 0){
					int tponto = 0;

					// Calcula pontos que vão ser inseridos
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 4)
							tponto += dado[i];
					}

					// Calcula pontos que vão ser inseridos
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][3] = tponto;
					break;
				}

				// Categoria já foi usada, sai e manda escolher outra
				else if (tabela[jogador][3] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 5:		// Cincos 

				// Repete o mesmo processo das anteriores
				if (tabela[jogador][4] == 0){
					int tpontos = 0;

					
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 5)
							tponto += dado[i];
					}


					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][4] = tponto;
					break;
				}

				
				else if (tabela[jogador][4] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 6:		// Seis 

				
				if (tabela[jogador][5] == 0){
					int tponto = 0;

					
					for (int i = 0; i < MAX_DADOS; ++i){
						if (dado[i] == 6)
							tponto += dado[i];
					}


					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogoador][5] = tponto;
					break;
				}


				else if (tabela[jogador][5] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 7:		// Trinca 

				
				if (tabela[jogador][6] == 0){
					int t[6];
					int tponto = 0;

					// Determina se saiu uma trinca 
					for (int i = 0; i < 6; ++i){
						t[i] = count(dado, dado + MAX_DADOS, i + 1);
						if (t[i] == 3){

							// Add valor dos dados 
							for (int j = 0; j < MAX_DADOS; ++j)
								tponto += dado[j];
						}
					}

					// Coloca ponto na tabela do jogador 
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][6] = tponto;
					break;
				}

				// Categoria já foi usada, sai e manda escolher outra
				else if (tabela[jogador][6] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 8:		//Quadra

				
				if (tabela[jogador][7] == 0){
					int t[6];
					int tponto = 0;

					//Mesma verificação da Trinca
					for (int i = 0; i < 6; ++i){
						t[i] = count(dado, dado + MAX_DADOS, i + 1);
						if (t[i] == 4){

							
							for (int j = 0; j < MAX_DADOS; ++j)
								tponto += dado[j];
						}
					}
					
					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][7] = tponto;
					break;
				}

				
				else if (tabela[jogador][7] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 9:		// Full House

				//Segue a mesma coisa da trinca e quadra
				if (tabela[jogador][8] == 0){
					int t[6];
					int fullHouse = 0;

					
					for (int i = 0; i < 6; ++i){
						t[i] = count(dado, dado + MAX_DADOS, i + 1);
						if (t[i] == 3)
							++fullHouse;
						else if (t[i] == 2)
							++fullHouse;
					}
					
					if (fullHouse == 2){
						tabela[jogador][8] = 25;
						break;
					}
					else {
						tabela[jogador][8] = -1;
						break;
					}

				}

				
				else if (tabela[jogador][8] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 10:	//Sequência Baixa

				
				if (tabela[jogador][9] == 0){
					int conta = 0;

					
					sort(dado, dado + MAX_DADOS);

					// Verifica sequencia 
					for (int i = 1; i < MAX_DADOS; ++i){
						if (dado[i] == dado[i - 1] + 1)
							++conta;
					}

					
					if (count > 3){
						tabela[jogador][9] = 30;
						break;
					}
					else {
						tabela[jogador][9] = -1;
						break;
					}
				}

				
				else if (tabela[jogador][9] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 11:	// Sequêcia Alta 

			
				if (tabela[jogador][10] == 0){
					int conta = 0;

					
					sort(dado, dado + MAX_DADOS);

					
					for (int i = 1; i < MAX_DADOS; ++i){
						if (dado[i] == dado[i - 1] + 1)
							++conta;
					}

					
					if (conta > 4){
						tabela[jogador][10] = 30;
						break;
					}
					else {
						tabela[jogador][10] = -1;
						break;
					}
				}


				else if (tabela[jogador][10] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 12:	//GENERAL


				if (tabela[jogador][11] == 0){
					int t[6];
					int tponto = 0;
	
					
					for (int i = 0; i < 6; ++i){
						t[i] = count(dado, dado + MAX_DADOS, i + 1);
						if (t[i] == 5)
							tponto = 50;	
					}


					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][11] = tponto;
					break;
				}


				else if (tabela[jogador][11] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			case 13:	//Jogada X

				
				if (tabela[jogador][12] == 0){
					int tponto = 0;


					for (int i = 0; i < MAX_DADOS; ++i)
						tponto += dado[i];


					if (tponto == 0){
						tponto = -1;
					}
					tabela[jogador][12] = tponto;
					break;
				}

				
				else if (tabela[jogador][12] != 0){
					cout << "Categoria já usada, selecione outra." << endl;
					repete = true;
					break;
				}

			default:
				cout << "Escolha inválida...Tente novamente." << endl;
				repete = true;
		}

	} while (repete);

exit_switch:;

	// Aplica bonus GENERAL 
	if (general) {
		tabela[jogador][11] += 100;
		cout << "Recebeu o bonus de GENERAL!" << endl;
	}
	
}

// Função calcula ponto. Calcula os pontos do jogador e verifica se aplica bonus 
void calcponto(vector<vector<int>> &tabela, int jogador){
	
	int Pontosalto = 0; 
	int Pontosbaixo = 0;

	// Reseta qualquer valor negativo pra 0
	for (int i = 0; i < PONTOS; ++i){
		if (tabela[jogador][i] == -1)
			tabela[jogador][i] == 0;
	}

	// Calculo Pontos maiores 
	for (int i = 0; i < 5; ++i){
		Pontosalto += tabela[jogador][i];
	}
	
	// Verifica bonus 
	if (Pontosalto > 62){
		Pontosalto += 35;
		cout << "Recebeu Pontos bonus!" << endl;
	}
		
	// Calcula ponto baixo 
	for (int i = 6; i < 12; ++i){
		Pontosbaixo += tabela[jogador][i];
	}

	// Passa pontos pro jogador 
	tabela[jogador][13] = Pontosalto + Pontosbaixo;
}

// Seleciona Ponto função. 
bool selponto(const vector<string>& i, const vector<string>& j) {
	return i[1] > j[1];
}

// Função Rank. Combina nome e tabela 
void Rank(vector <vector<int>> &tabela, vector<string> &get_nome, int MAX_JOG){
	
	
	vector<vector<string>> Rank;
	for (int i = 0; i < MAX_JOG; ++i){

		// Cria vetor temporario q segura os dados 
		vector<string> t;
		for (int j = 0; j < 2; ++j){

			// Carrega nomes na primeira coluna
			if (j == 0)
				temp.push_back(get_nome[i]);

			//Carrega pontos na segunda coluna
			if (j == 1)
				t.push_back(static_cast<ostringstream*>(&(ostringstream() << tabela[i][13]))->str());
		}
		// Colaca vetor temporario no vetor Rank 
		Rank.push_back(t);
	}	

	//Seleciona o rank e coloca pontuações
	sort(Rank.begin(), Rank.end(), selponto);

	cout << Rank[0][0] << " Ganhou!" << endl << endl;

	// Mostra vetor Rank
	cout << "Rank do Jogador: " << endl;
	for (/*unsigned*/ int i = 0; i<Rank.size(); ++i) {
		cout << i + 1 << ") ";
		for (/*unsigned*/ int j = 0; j<Rank[i].size(); ++j) {
			cout << Rank[i][j] << "   ";
		} cout << endl;
	} cout << endl;
}


int main(){

	
	bemvindo();

	
	const int MAX_JOG = getNum_jogadores();

	
	vector<string> nome_jog(MAX_JOG);
	for (int i = 0; i < MAX_JOG; ++i){
		Nome_jog[i] = getNome(i);
	}

	/* Initialize the roundScores vector and fill elements with 0 */
	vector<vector<int>> roundScore(MAX_JOG, vector<int>(MAX_JOG,0));

	int turno = 0;
	bool repete = false;
	do {

		/* Initialize the scoreCard vector and fills elements with 0 */
		vector<vector<int>> scoreCard(MAX_PLAYERS, vector<int>(PONTOS, 0));
		
		/* Seed rand() with time */
		srand(time(NULL));

		/* Initialize die array */
		int die[MAX_DADOS];

		/* Play until all turns are completed */
		for (int turn = 0; turn < MAX_TURNOS; ++turno){
			
			/* Have each player roll and place a score each turn */
			for (int player = 0; player < MAX_JOG; ++jogador){

				cout << "Turn " << turn + 1 << endl;
				cout << " | "<< playerName[player] << "'s Turn.\n" << endl;

				/* Initialize die array and get values */
				GiraDado(die);

				/* Score player's roll */
				placeScore(die, scoreCard, player);

			}
		} cout << "Round Over!" << endl;
		
		/* Calculate Scores */
		for (int i = 0; i < MAX_PLAYERS; ++i)
			calcScore(scoreCard, i);

		/* Rank scores and display winner */
		scoreRanking(scoreCard, playerName, MAX_PLAYERS);

		
		/* Collect final scores for round per player */
		for (int i = 0; i < MAX_PLAYERS; ++i){
			roundScore[round][i] = scoreCard[i][13];
		}

		/* Ask to display round scores */
		cout << "Display All Round Scores? (y/n)";
		char option;
		cin >> option;
		if (toupper(option) == 'Y'){

			/* Print played round numbers */
			for (int i = 0; i < round + 1; ++i){
				cout << "\tRound " << round + 1;
			} cout << endl;

			/* print player names and their final score for each round played */
			for (int i = 0; i < MAX_PLAYERS; ++i){
				cout << playerName[i] << "\t";
				for (int j = 0; j < round+1; ++j)
					cout << roundScore[j][i] << "\t";
				cout << endl;
			} cout << endl;
		}

		/* Ask to play another round, if max rounds not played */
		if (round < MAX_JOG){
			cout << "Play another round? (y/n)";
			char replay;
			cin >> replay;
			if (toupper(replay) == 'Y'){
				repeat = true;
				++round;
			}	
		}
		else{	 /* Max rounds played, end game */
			repeat = false;
		}

		
	} while (repeat);

	cout << "Game Over!" << endl;

	/* Pause and Return */
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

/*
Projeto Bilheteria:
Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupação que ofereça as seguintes opções, através de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupação
3.	Faturamento

A opção 1 deverá solicitar a informação da fileira e da poltrona.
Os dados devem ser consistidos no sentido da garantia de serem válidos. 
Caso o lugar esteja vago, efetuar a reserva e informar o usuário do sucesso da operação. 
Caso o lugar já se encontre ocupado, alertar o usuário com uma mensagem.

A opção 2 deverá gerar na tela um “mapa” de ocupação do teatro com uma legenda onde:

‘.’ representa lugar vago
‘#’ representa lugar ocupado
A opção 3 deverá apresentar na tela as seguintes informações:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

•	Fileiras 1 a 5:		R$ 50,00
•	Fileiras 6 a 10:	R$ 30,00
•	Fileiras 11 a 15:	R$ 15,00
*/

#define LIN 15
#define COL 40

void ReservarPoltrona(int **mat){
	int fileira, numPoltrona;
	
	cout << "Digite a fileira da poltrona:" << endl;
	cin >> fileira;
	cout << "Digite o numero da poltrona:" << endl;
	cin >> numPoltrona;
	
	if (fileira < 1 || fileira > 15 || numPoltrona < 1 || numPoltrona > 40) {
		cout << "Posicao invalida!\n";
	}
	
	if(mat[fileira][numPoltrona] == 0){
		mat[fileira][numPoltrona] = 1;
		cout << "Poltrona reservada com sucesso." << endl;
	}else{
		cout << "Poltrona ocupada." << endl;
	}
	
}
void MostrarMapa(int **mat){
    for(int i = 0; i < LIN; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			cout << mat[i][j] << " | "; 
		}
		cout << endl;
	}
	cout << endl;
}
void CalcularFaturamento(int **mat){
	int lugares;
	double valorBilheteria;
	
	for(int i = 0; i < LIN; i++){
		for(int j = 0; j < COL; j++){
			if(mat[i][j] == 1){
				lugares++;
				if(i < 5){
				;valorBilheteria += 50;
				}
				if( (i >= 5) && (i < 10)){
				;valorBilheteria += 30;
				}
				if( (i >= 10) && (i < 15)){
				;valorBilheteria += 15;
				}
			}
			
		}
	}
	
	cout << "Quantidade de lugares ocupados: " << lugares << endl;
	cout << "Valor da blheteria: R$" << valorBilheteria << endl;
}

int main(int argc, char** argv){
	int entrada;
	//Declarando matriz
	int **mat;
	
	//Inicializando linhas e colunas
	mat = new int*[LIN];
	for(int i = 0; i < LIN; i++){
		mat[i] = new int[COL];
	}
	
	//Preenchendo a matriz	
	for(int i = 0; i < LIN; i++){
		for(int j = 0; j < COL; j++){
			if(j % 2 == 0){
				mat[i][j] = 1;	
			}else{
				mat[i][j] = 0;
			}
			
		}
	}
	
	do{
		cout<< "0.	Finalizar" << endl;
		cout<< "1.	Reservar poltrona" << endl;
		cout<< "2.	Mapa de ocupação" << endl;
		cout<< "3.	Faturamento" << endl;
	
		cin >> entrada; 
	
		switch(entrada)
		{
		case 0:
			cout << "Programa Finalizado." << endl;
			break;
		case 1:
			ReservarPoltrona(mat);
			break;
		case 2:
			MostrarMapa(mat);
			break;
		case 3:
			CalcularFaturamento(mat);
			break;
		default:
			cout << "Escolha uma opção!" << endl;
			break;
		}
		}while(entrada != 0);
}

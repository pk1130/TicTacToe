#include <iostream>
#include <process.h>
#include <fstream>

using namespace std;

/* 
	The TicTacToe class contains all the function and variable declarations 
	required to make a working game of 2-player TicTacToe.
*/

class TicTacToe{
		private:
			int game;

		public:
			char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
			int checkwin();
			void board();
			int retgame()
			{
				return game;
			}
			
			void increasevalue()
			{
				game++;
			}
			
			void getfromfile()
			{
				fstream f2("STORE.TXT");
				f2>>game;
			}
			
			void putintofile()
			{
				fstream f2("STORE.TXT");
				f2<<game;
			}
}T;


/*
	This function is used to determine the status of the game. If the status is 
	1, the game is over and one of the players has won the game. If the status
	is -1, the game is still in progress. If the status is 0, the game is over 
	and the players have drawn.
*/
int TicTacToe:: checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

/*
	This function is used to draw and align the Tic-Tac-Toe board with each
	player's marl (X or O) for gameplay
*/
void TicTacToe:: board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

int main()
{
	int player = 1, i, choice;
	char mark;

	do
	{
		T.board();
		player = (player%2) ? 1 : 2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && T.square[1] == '1')
			T.square[1] = mark;
		else if (choice == 2 && T.square[2] == '2')
			T.square[2] = mark;
		else if (choice == 3 && T.square[3] == '3')
			T.square[3] = mark;
		else if (choice == 4 && T.square[4] == '4')
			T.square[4] = mark;
		else if (choice == 5 && T.square[5] == '5')
			T.square[5] = mark;
		else if (choice == 6 && T.square[6] == '6')
			T.square[6] = mark;
		else if (choice == 7 && T.square[7] == '7')
			T.square[7] = mark;
		else if (choice == 8 && T.square[8] == '8')
			T.square[8] = mark;
		else if (choice == 9 && T.square[9] == '9')
			T.square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=T.checkwin();
		player++;
	} while (i==-1);
	
	T.board(); 
	fstream f1("WINNER.TXT", ios::app); 
	T.getfromfile();
	
	if (i==1)
		{
			cout<<"==>\aPlayer "<<--player<<" wins ";
			T.increasevalue(); 
			f1<<" Player "<<player<<"  has won game "<<T.retgame()<<endl;
		}
	else
		{
			cout<<"==>\aGame draw"; T.increasevalue();
			f1<<" Game"<<T.retgame()<<" is a draw "<<endl;
		}
	T.putintofile();
	
	cin.ignore();
	cin.get();
	return 0;
}

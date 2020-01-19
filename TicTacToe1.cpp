#include<iostream>
#include<process.h>
#include<fstream>

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
	This function is used to draw and align the Tic-Tac-Toe board for gameplay
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

#include<iostream>
#include<process.h>
#include<fstream>

using namespace std;

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



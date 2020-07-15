
#include <iostream>
#include<conio.h>

using namespace std;

char box[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int flag;

void viewBoard();
int winCheck();

int main()
{
	int player = 1, i, choice = 0;
	char mark;

	do 
	{
		viewBoard();
		player = (player % 2) ? 1 : 2;

		cout << "\nPlayer " << player << " enter a number: ";
		cin >> choice;
		
		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && box[0] == '1')
			box[0] = mark;
		else if (choice == 2 && box[1] == '2')
			box[1] = mark;
		else if (choice == 3 && box[2] == '3')
			box[2] = mark;
		else if (choice == 4 && box[3] == '4')
			box[3] = mark;
		else if (choice == 5 && box[4] == '5')
			box[4] = mark;
		else if (choice == 6 && box[5] == '6')
			box[5] = mark;
		else if (choice == 7 && box[6] == '7')
			box[6] = mark;
		else if (choice == 8 && box[7] == '8')
			box[7] = mark;
		else if (choice == 9 && box[8] == '9')
			box[8] = mark;
		else
		{ 
			cout << "Invalid Move!\n";
			player--;
			cin.ignore();
			cin.get();
		}
				
			i = winCheck();
			player++;
			
	} while (i == -1);

	viewBoard();
	
	if (i == 1)
		cout << "\n\tPlayer " << --player << " Wins!\n";
	else
		cout << "\n\tGame Draw!\n";

	cin.ignore();
	cin.get();

	return 0;
}

void viewBoard()
{
	cout << "\t   Tic Tac Toe Game\n\n";
	cout << "Player 1 = X \t\t Player 2 = O\n";

	cout << "\n\t _______________________\n";
	cout << "\t|\t|\t|\t|\t\n";
	cout << "\t|   " << box[0] << "   |   " << box[1] << "   |   " << box[2] << "   |\t\n";
	cout << "\t|_______|_______|_______|\n";
	cout << "\t|\t|\t|\t|\t\n";
	cout << "\t|   " << box[3] << "   |   " << box[4] << "   |   " << box[5] << "   |\t\n";
	cout << "\t|_______|_______|_______|\n";
	cout << "\t|\t|\t|\t|\t\n";
	cout << "\t|   " << box[6] << "   |   " << box[7] << "   |   " << box[8] << "   |\t\n";
	cout << "\t|_______|_______|_______|\n";

}

int winCheck()
{
	system("cls");

	if (box[0] == box[1] && box[1] == box[2])
		flag = 1;
	else if (box[3] == box[4] && box[4] == box[5])
		flag = 1;
	else if (box[6] == box[7] && box[7] == box[8])
		flag = 1;
	else if (box[0] == box[3] && box[3] == box[6])
		flag = 1;
	else if (box[1] == box[4] && box[4] == box[7])
		flag = 1;
	else if (box[2] == box[5] && box[5] == box[8])
		flag = 1;
	else if (box[0] == box[4] && box[4] == box[8])
		flag = 1;
	else if (box[2] == box[4] && box[4] == box[6])
		flag = 1;
	else if (box[0] != '1' && box[1] != '2' && box[2] != '3' && box[3] != '4' && box[4] != '5' && box[5] != '6' && box[6] != '7' && box[7] != '8' && box[8] != '9')
		flag = 0;
	else
		return -1;

	return flag;
}


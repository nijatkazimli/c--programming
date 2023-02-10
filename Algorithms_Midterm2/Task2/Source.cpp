#include <iostream>
#include <windows.h>
#include "Card.h"
using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	int num1 = 0;
	int* deck1 = nullptr;
	cout << "Enter the number of the first player's cards:\n";
	cin >> num1;
	deck1 = new int[num1];
	cout << "Enter the strength of the cards seperated by spaces:"<<endl;
	for (int i = 0; i < num1; i++)
		cin >> deck1[i];

	cout << endl << endl;

	int num2 = 0;
	int* deck2 = nullptr;
	cout << "Enter the number of the second player's cards:" << endl;
	cin >> num2;
	deck2 = new int[num2];
	cout << "Enter the strength of the cards seperated by spaces:"<<endl;
	for (int i = 0; i < num2; i++)
		cin >> deck2[i];

	Card card(num1, deck1, num2, deck2);
	cout << endl;
	

	SetConsoleTextAttribute(h, 23);
	cout << "Player 1 needs " << card.guaranteed_victory() << " dollars to maintain a guaranteed victory" << endl;
	SetConsoleTextAttribute(h, 2);


	return 0;
}
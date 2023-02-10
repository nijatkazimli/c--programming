#pragma once
class Card
{
private:
	int* deck1 = nullptr;
	int* deck2 = nullptr;
	int num1 = 0;
	int num2 = 0;
public:
	Card(int num1, int* deck1, int num2, int* deck2);
	~Card();
	int guaranteed_victory();
};


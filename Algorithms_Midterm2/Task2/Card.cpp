#include "Card.h"

Card::Card(int num1, int* deck1, int num2, int* deck2) : num1(num1), deck1(deck1), num2(num2), deck2(deck2)
{
}

int find_max(int* arr, int num)
{
	if (!arr)
		return -1;
	int max = arr[0];
	for(int i = 1;i<num;i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

Card::~Card()
{
	delete deck1;
	delete deck2;
}

int Card::guaranteed_victory()
{
	bool is_lucky = true;
	for(int a=0;a<num1;a++)
	{
		for(int b=0;b<num2;b++)
		{
			if(deck2[b]>deck1[a])
			{
				is_lucky = false;
				break;
			}
		}
	}
	if (is_lucky)
		return 0;
	else
	{
		int money = 0;
		int max_deck2 = find_max(deck2, num2);
		if (max_deck2 == -1)
			return 0;

		for(int a = 0;a<num1;a++)
		{
			if (deck1[a] <= max_deck2)
				money += max_deck2 - deck1[a] + 1;
		}
		return money;
	}



	return 0;
}

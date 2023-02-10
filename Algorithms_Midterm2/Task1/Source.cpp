#include <iostream>
#include <list>
#include <string>
using namespace std;

int count_substring(string input, string subset);

int main()
{
	string input = "";
	cout << "Input your string (X): ";
	cin >> input;
	string subset = "";
	cout << "Input your string (S): ";
	cin >> subset;
	cout << "Output: " << count_substring(input, subset);
	return 1;
}

int count_substring(string input, string subset)
{
	if (input.empty() || subset.empty()) // if input or subset is empty, there is no point in continuing the function
		return 0;
	string substring = "";
	list<string> substrings;
	substrings.push_back("" + input[0]); // for some reason the code below never included the first character as a substring
										// so I did it manually
	//Picking a start point
	for (int len = 1; len <= input.length(); len++)
	{
		//Picking an end point
		for (int i = 0; i <= input.length() - len; i++)
		{
			//storing characters from the start to the end in a substring variable
			int j = i + len - 1;
			for (int k = i; k <= j; k++)
				substring.push_back(input[k]);
			//pushing it to substrings
			substrings.push_back(substring);
			substring = "";
		}
	}
	int count = 0;
	for(string str : substrings)
	{
		//helper variable if the substring contained all the characters
		bool flag = true;
		for(int i=0;i<subset.length();i++)
		{
			if(!str.contains(subset[i]))
			{
				//if it did not I assigned false to my helper variable, then broke the loop as I do not care about the rest of characterss
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		//if it contained I incremented my counter
		else
			count++;
	}

	return count;
}

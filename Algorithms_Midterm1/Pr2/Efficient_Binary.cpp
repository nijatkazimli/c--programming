#include <iostream>
#include <string>
#include <queue>
using namespace std;

void generate(int n)
{
	//It makes a lot of sense to use strings since we append 0 or 1 to the numbers.
	queue<string> q;
	q.push("1"); // we start by adding 1 at the beginning.

	for(int i=0;i<n;i++)
	{
		q.push(q.front() + "0"); // I append 0 to the first element of the queue, and push it.
		q.push(q.front() + "1"); // I append 1 to the first element of the queue, and push it.

		cout << q.front() << " "; // I print the first element of the queue before removing it.
		q.pop(); // I remove it because I have to append 0 and 1 to subsequent elements.
	}
}

int main()
{
	int N = 0;
	cout << "Enter your N: ";
	cin >> N;
	generate(N);
	
	return 0;
}
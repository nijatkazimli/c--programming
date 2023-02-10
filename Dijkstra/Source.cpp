#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph G(3); // Graph with negative edges
	G.add_edge(0, 1, 5);
	G.add_edge(0, 2, 6);
	G.add_edge(2, 1, -3);

	for (int i = 0; i < G.get_v(); i++)
	{
		G.shortest_path(i);
		cout << endl;
	}

	cout << endl << endl;
	return 0;
}
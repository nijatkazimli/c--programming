#pragma once
using namespace std;
#include <list>
#include <queue>

class Graph
{
	int v; // the number of vertices to be stored
	list<pair<int,int>>* adj;
public:
	Graph(int vertex);
	void add_edge(char u, char v, int w);
	void shortest_path(int s);
	int get_v();
};
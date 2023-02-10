#pragma once
using namespace std;
#include <list>

class Heist
{
	int v = 0;
	list<pair<int, int>>* adj = nullptr;
	int* police = nullptr;
	int s = 0;
	int d = 0;
public:
	Heist(int vertex);
	~Heist();
	void add_edge(int u, int v, int t);
	void police_setter(int* police);
	void position_setter(int& s, int& d);
	int shortest_safe_path() const;
};


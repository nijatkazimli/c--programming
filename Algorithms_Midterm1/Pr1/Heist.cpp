#include "Heist.h"
#include <queue>

#define INF INT_MAX

Heist::Heist(int vertex)
{
	this->v = vertex;
	this->adj = new list<pair<int, int>>[vertex];
}

Heist::~Heist()
{
	delete[] adj;
}

void Heist::add_edge(int u, int v, int t)
{
	adj[u].push_back(make_pair(v, t)); // it means from vertex u to v, it costs t
	adj[v].push_back(make_pair(u, t)); // because it is bidirectional
}

void Heist::police_setter(int* police)
{
	this->police = police;
}

void Heist::position_setter(int& s, int& d)
{
	this->s = s;
	this->d = d;
}

int Heist::shortest_safe_path() const
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(v, INF);
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		list<pair<int, int>>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i)
		{
			int v = i->first;
			int time = i->second;

			if(dist[v] > dist[u] + time && police[u] == 0 && police[v] == 0)
			{
				dist[v] = dist[u] + time;
				pq.push(make_pair(dist[v], v));
			}
		}

	}
	
	if (dist[d] == INF)
		return -1;
	else
		return dist[d];
}

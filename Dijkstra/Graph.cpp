#include "Graph.h"
using namespace std;
#include <map>
#include <string>

#define INF INT_MAX

Graph::Graph(int vertex)
{
	this->v = vertex;
	this->adj = new list<pair<int, int>>[vertex];
}

void Graph::add_edge(char u, char v, int w) // w represents weights, u and v represent the ends of the new edge (vertices)
{
	adj[u].push_back(make_pair(v, w));  // it means from vertex u to v, it costs w
}

void Graph::shortest_path(int src) // src represents source vertex
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(v, INF); // All distance from the source are infinite
	pq.push(make_pair(0, src)); // push source to the queue
	dist[src] = 0; // source's distance is 0 as we are already there

	while(!pq.empty())
	{
		int u = pq.top().second; // I store the vertex label
		pq.pop(); // I remove it from the queue

		list<pair<int, int>>::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			// I get the vertex label and weight of the current adjacent of u
			int v = (*i).first;
			int weight = (*i).second;

			if(dist[v] > dist[u] + weight) // if I find the better path
			{
				dist[v] = dist[u] + weight; // I update the distance
				pq.push(make_pair(dist[v], v)); // and push it pack to the queue
			}
		}
	}
	for(int i = 0; i<v;i++)
	{
		if(dist[i]==INF)
			printf("%c --> %c \t\t %s\n", src + 65, i + 65, "infinite"); // the shortest distance from the source
		else
			printf("%c --> %c \t\t %d\n", src + 65, i + 65, dist[i]); // the shortest distance from the source
	}
}

int Graph::get_v()
{
	return v;
}


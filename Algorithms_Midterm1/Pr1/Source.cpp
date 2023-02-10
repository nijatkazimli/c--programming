#include <iostream>
#include "Heist.h"	
using namespace std;

int main()
{
	int T, N, s, d, M;
	int* P;
	// T - the number of test cases
	// N - the number of junctions
	// P - the array storing the info about which junctions have the police
	// s - the junction with the crew (start point)
	// d - the junction with the safehouse (target point)
	// M - the number of bidirectional roads

	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cout << "Test case number " << i << endl;
		cin >> N;
		Heist H(N);
		P = new int[N];
		for (int i = 0; i < N; i++)
			cin >> P[i];
		H.police_setter(P);
		cin >> s >> d;
		H.position_setter(s, d);
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int u, v, t;
			cin >> u >> v >> t;
			H.add_edge(u, v, t);
		}
		cout << "Output: " << H.shortest_safe_path() << endl;

		delete[] P;
	}

	return 0;
}

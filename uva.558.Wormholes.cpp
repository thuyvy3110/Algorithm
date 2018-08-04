/*
* https://www.spoj.com/problems/TRVCOST/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define max 10000

struct triad{
    int source;
    int target;
    int weight;
};

const int inf = 1e9; //10^9
vector<triad> graph;
vector<int>dist(max, inf);
int n, m;
int path[max];

bool bellmanford(int s)
{
	int u,v,w;
	dist[s] = 0; // chi phi duong di

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j < m; j++){
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if (dist[u] != inf && (dist[u] + w < dist[v]))
			{
				dist[u] = dist[u] + w;
				path[v] = u;
			}
        }
    }
    for(int i = 0; i < m; i++){
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if (dist[u] != inf && (dist[u] + w < dist[v]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
	int c, x, y, t;
	cin >> c;

	for(int i = 0; i < c ; i++){

        cin >> n >> m;

        vector<int>dist (n + 10,inf);
        triad temp;

        for(int j = 0;j < m; j++){

            cin >> x >> y >> t;

            temp.source = x;
            temp.target = y;
            temp.weight = t;

            graph.push_back(temp);
        }

        bool res = bellmanford(0);

        if(res == false){
            cout << "not possible" << endl;
        }
        else
            cout << "possible" << endl;
	}

	return 0;
}

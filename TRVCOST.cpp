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

#define max 500

const int inf = 1e9; //10^9
vector<vector<pair<int, int>>> graph;
vector<int>dist(max, inf);
int path[max];

struct option {
	bool operator() (const pair<int, int>&a, pair<int, int>&b)
		const {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;

void dijkstra(int u)
{
	//priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
	pq.push(make_pair(u, 0));
	dist[u] = 0; // chi phi duong di

	while (!pq.empty()) {
		pair<int, int> top = pq.top(); 
		pq.pop(); //lay (dinh, chi phi) ra khoi hang doi
		int tf = top.first; //dinh
		int df = top.second; //chi phi

		for (int i = 0; i < graph[tf].size(); ++i) {
			pair<int, int> neighbor = graph[tf][i];
			if (df + neighbor.second < dist[neighbor.first])                                                                                                                                            
			{
				dist[neighbor.first] = df + neighbor.second;
				pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
				path[neighbor.first] = tf;
			}
		}
	}
}

int main()
{
	int ans = 0;
	int n; // N the number of roads that government constructed
	int a, b; //A and B represent the locations between which the road was constructed
	int w; //W is the fixed cost for travelling from A to B or from B to A
	int u;  //location U
	int q; //Q number of other locations (destination)
	int v; //V (destination) for which minimum cost is to be found from U

	dist = vector<int>(max, inf);
	graph = vector<vector<pair<int, int>>>(max + 10, vector<pair<int, int>>());

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> w;
		if (w > 0) {
			graph[a].push_back(pair<int, int>(b, w));
			graph[b].push_back(pair<int, int>(a, w));
		}
	}

	cin >> u; // where Rohit wants to travel to other locations

	dijkstra(u);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> v;
		ans = dist[v];
		if (ans != inf)
			cout << ans << endl;
		else
			cout << "NO PATH" << endl;
	}
	return 0;
}

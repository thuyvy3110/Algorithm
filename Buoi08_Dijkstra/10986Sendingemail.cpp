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

#define max 200000

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
	int N;
	int n;
	int m;
	int S, a;
	int T, b;
	int w;

	cin >> N;
    vector<int> result(N+10, inf);
	for(int i = 0; i < N; i++){
        cin >> n >> m >> S >> T;

        dist = vector<int>(n+10, inf);
        graph = vector<vector<pair<int, int>>>(n+10, vector<pair<int, int>>());

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
                graph[a].push_back(pair<int, int>(b, w));
                graph[b].push_back(pair<int, int>(a, w));
        }

        dijkstra(S);
        result[i] = dist[T];
	}
    for (int i=0; i < N; ++i){
        cout << "Case #" << i +1 << ": ";
        if(result[i] != inf)
            cout << result[i] << endl;
        else
            cout << "unreachable" << endl;
	}

	return 0;
}

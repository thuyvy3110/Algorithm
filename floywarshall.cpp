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
#define INF 1e9
#define M   500

const int inf = 1e9; //10^9
vector<vector<int>> graph;
vector<vector<int>> dist;
vector<vector<int>> path;
int n;

void printPath(int s, int t){
    int b[max];
    int m = 0;
    while(s!=t){
        b[m++] = t;
        t = path[s][t];
    }
    b[m++] = s;
    for (int i = m-1; i >= 0; i--){
        cout << b[i] << "";
    }
}

bool floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& dist, int& h)
{
	int i,j,k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
			dist[i][j] = graph[i][j];
			if (graph[i][j] != inf && i != j)
			{
				path[i][j] = i;
			}
            else
            {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = graph[i][j];
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                     dist[i][j] = dist[i][k] + dist[k][j];
                     path[i][j] = path[k][j];
                }
            }
        }
    }
}

int main()
{
	int T, b;
	string a = "";

	cin >> T;

    graph = vector<vector<int>> (M, vector<int>(M));
    dist = vector<vector<int>> (M, vector<int>(M));
    path = vector<vector<int>> (M, vector<int>(M));

	for(int i = 0; i < T; i++){
        for(int j = 0; j < T; j++){
            cin >> a;
            if(a == "Y"){
                graph[i][j] = 1;
            }
            else if(a == "N"){
                graph[i][j] = 0;
            }
        }
	}

    for(int i = 0; i < T; i++){
        for(int j = 0; j < T; j++){
            cout << graph[i][j];
         }
	}

	int h = 0;

	floydWarshall(graph, dist, h);

	system("pause");

	//int result = dist[][];
    getchar();

	return 0;
}

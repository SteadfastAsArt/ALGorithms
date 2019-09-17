#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e9;

vector<vector<int> > G;
// s[]: visited state
// dist[]: recorded distance from certain src
// prev[]: recorded trajectory
int s[maxn], dist[maxn], prev[maxn];


void readGraph()
{

}


int find_unvisited_min()
{
    int u = -1;
    // Exhausted search or Min-Heap of dist[]
    /// ...
    // update s[]
    return u;
}

void dijkstra(int src){
	
	int n = G.size();
	memset(s, 0, sizeof(int) * maxn );
	for(int i = 0; i < n; i++) dist[i] = INFINITY;
	for(int i = 0; i < n; i++) prev[i] = -1;
	
	dist[src] = 0;  // This is trivial...
	
	while(true)
	{
        /* 
         * Unvisited: each node in process once 
         * Min: guarantee optimal
         */
		int u = find_unvisited_min();
        if(u == -1)  break;

		for(int v = 0; v < G[u].size(); v++)
		{
			if (dist[u] + G[u][v] < dist[v])  // Greedy | based on "unvisited min"
			{
				dist[v] = dist[u] + G[u][v];
				prev[v] = u;
			}
		}
	}

}


int main() {
	readGraph();
    int src;
    cin >> src;
    dijkstra(src);
	
	return 0;
}
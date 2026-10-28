/*
MORE EXAM VARIATION: Shortest route required to pass through checkpoint V
Change from teacher's code: Run Dijkstra from A and from V; answer dist_A[V]+dist_V[B].
Input example (numbers only, entered in this order):
4 4
1 2 2
2 3 2
3 4 2
1 4 3
1 3 4
Expected labeled output: Minimum cost via required checkpoint 3: 6
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector<pair<int,int>> adj[1000]; // <edge cost, neighbor>
vector<int> dijkstra(int source)
{
    vector<int> dist(n+1,100000000);
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[source]=0; pq.push({0,source});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
    return dist;
}
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A,V,B;
    cout << "Enter start, required checkpoint, and destination: ";
    cin >> A >> V >> B;
    vector<int> fromA=dijkstra(A),fromV=dijkstra(V); // MAIN CHANGE: two runs
    if(fromA[V]==100000000 || fromV[B]==100000000)
        cout << "Result: No route through the checkpoint.\n";
    else
        cout << "Minimum cost via required checkpoint " << V << ": "
             << fromA[V]+fromV[B] << "\n";
}

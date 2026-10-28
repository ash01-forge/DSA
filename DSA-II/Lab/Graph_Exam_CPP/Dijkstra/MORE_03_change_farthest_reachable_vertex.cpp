/*
MORE EXAM VARIATION: Find farthest reachable vertex by shortest-path distance
Change from teacher's code: Run Dijkstra to all vertices, then scan dist[] for maximum finite distance.
Input example (numbers only, entered in this order):
4 3
1 2 2
2 3 3
1 4 4
1
Expected labeled output: Farthest reachable vertex: 3; Its shortest-path distance: 5
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000];
vector<pair<int,int>> adj[1000]; // <nonnegative edge weight,neighbor>
void dijkstra(int A)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[A]=0; pq.push({0,A});
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
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A; cout << "Enter source vertex: "; cin >> A;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    int farthest=A;
    for(int i=1;i<=n;i++)
        if(dist[i]!=100000000 && dist[i]>dist[farthest])
            farthest=i; // MAIN CHANGE: maximum among finite shortest distances
    cout << "Farthest reachable vertex: " << farthest << "\n";
    cout << "Its shortest-path distance: " << dist[farthest] << "\n";
}

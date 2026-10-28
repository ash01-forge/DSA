/*
MORE EXAM VARIATION: Determine whether a negative cycle makes target cost unbounded
Change from teacher's code: After n-1 rounds, propagate improvable vertices through outgoing edges.
Input example (numbers only, entered in this order):
5 5
1 2 1
2 3 -2
3 2 1
3 4 2
1 5 5
1 4
Expected labeled output: Negative cycle can affect destination 4: YES
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge { int u,v,w; };
int n,m,dist[1000];
bool affected[1000];
vector<Edge> edges;
vector<int> adj[1000];
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
        adj[e.u].push_back(e.v); // direction matters
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    const int INF=100000000;
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[A]=0;
    for(int round=1;round<n;round++)
        for(Edge e:edges)
            if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w)
                dist[e.v]=dist[e.u]+e.w;
    queue<int> q;
    for(Edge e:edges)
        if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w && !affected[e.v])
        { affected[e.v]=true; q.push(e.v); }
    // MAIN CHANGE: any vertex reachable from an improvable vertex is affected.
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
            if(!affected[v]) { affected[v]=true; q.push(v); }
    }
    cout << "Negative cycle can affect destination " << B << ": "
         << (affected[B] ? "YES" : "NO") << "\n";
    if(!affected[B] && dist[B]==INF)
        cout << "Destination is unreachable from source.\n";
    else if(!affected[B])
        cout << "Finite minimum cost to destination: " << dist[B] << "\n";
}

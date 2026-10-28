/*
NEW EXAM VARIATION: Shortest distance and route with negative edges
Change from teacher's code: Update parent[v] during relaxation and reverse the destination-to-source route.
Input example (enter the numbers in order, without this explanatory text):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1 4
Expected labeled output: Minimum cost: 5; Shortest path: 1 2 3 4
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,dist[1000],parent[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <weight,<from,to>>
bool bellman_ford(int source)
{
    for(int i=1;i<=n;i++) { dist[i]=INF; parent[i]=-1; }
    dist[source]=0;
    for(int round=1;round<n;round++)
        for(auto edge:edges)
        {
            int w=edge.first,u=edge.second.first,v=edge.second.second;
            if(dist[u]!=INF && dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u; // MAIN CHANGE: save previous vertex
            }
        }
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(dist[u]!=INF && dist[v]>dist[u]+w) return false;
    }
    return true; // no negative cycle reachable from source
}
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed edge " << i+1 << " as: from to signed_weight: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    int A,B;
    cout << "Enter source and destination vertices: "; cin >> A >> B;
    if(!bellman_ford(A))
    { cout << "Result: Reachable negative cycle; shortest route undefined.\n"; return 0; }
    if(dist[B]==INF)
    { cout << "Result: Destination unreachable.\n"; return 0; }
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current);
    reverse(path.begin(),path.end());
    cout << "Minimum cost: " << dist[B] << "\n";
    cout << "Shortest path: ";
    for(int vertex:path) cout << vertex << " ";
    cout << "\n";
}

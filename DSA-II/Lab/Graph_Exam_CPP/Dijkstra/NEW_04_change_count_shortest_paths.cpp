/*
NEW EXAM VARIATION: Count how many shortest routes exist
Change from teacher's code: Maintain ways[v]; replace on a shorter distance and add on an equal distance.
Input example (enter the numbers in order, without this explanatory text):
4 4
1 2 1
1 3 1
2 4 1
3 4 1
1 4
Expected labeled output: Minimum cost: 2; Number of shortest routes: 2
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MOD=1000000007;
int n,m,dist[1000],ways[1000];
vector<pair<int,int>> adj[1000]; // positive edge weights required here
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0; ways[start]=1; pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w)
            {
                dist[v]=d+w;
                ways[v]=ways[u]; // new shorter distance: replace old count
                pq.push({dist[v],v});
            }
            else if(dist[v]==d+w)
                ways[v]=(ways[v]+ways[u])%MOD; // equal distance: add routes
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected positive-weight edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 positive_weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; ways[i]=0; }
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: No route.\n";
    else
    {
        cout << "Minimum cost: " << dist[B] << "\n";
        cout << "Number of shortest routes: " << ways[B] << "\n";
    }
}

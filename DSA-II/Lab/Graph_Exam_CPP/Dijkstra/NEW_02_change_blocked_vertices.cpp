/*
NEW EXAM VARIATION: Shortest route while some vertices are closed
Change from teacher's code: Read K blocked vertices; never enter or expand them.
Input example (enter the numbers in order, without this explanatory text):
4 4 1
1 2 1
2 4 1
1 3 5
3 4 1
2
1 4
Expected labeled output: Minimum cost avoiding blocked vertices: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,dist[1000];
bool blocked[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0; pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,node=p.second;
        if(d!=dist[node] || blocked[node]) continue;
        for(auto it:adj[node])
        {
            int w=it.first,v=it.second;
            if(blocked[v]) continue; // MAIN CHANGE: do not enter closed vertex
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices, undirected edges, and number of blocked vertices: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    for(int i=0;i<k;i++)
    {
        int x;
        cout << "Enter blocked vertex " << i+1 << ": "; cin >> x;
        blocked[x]=true;
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    if(blocked[A] || blocked[B])
    { cout << "Result: Source or destination is blocked.\n"; return 0; }
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: No permitted route.\n";
    else cout << "Minimum cost avoiding blocked vertices: " << dist[B] << "\n";
}

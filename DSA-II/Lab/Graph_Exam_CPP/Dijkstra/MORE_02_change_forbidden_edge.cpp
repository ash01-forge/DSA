/*
MORE EXAM VARIATION: Shortest route avoiding one closed road
Change from teacher's code: Skip both directions of one specified undirected edge during relaxation.
Input example (numbers only, entered in this order):
4 4
1 2 1
2 4 1
1 3 3
3 4 1
2 4
1 4
Expected labeled output: Minimum cost avoiding closed road: 4
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000],X,Y;
vector<pair<int,int>> adj[1000];
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
            // MAIN CHANGE: road X-Y is closed in BOTH directions.
            if((u==X && v==Y) || (u==Y && v==X)) continue;
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected weighted roads: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: vertex_1 vertex_2 time: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    cout << "Enter endpoints of the closed road: "; cin >> X >> Y;
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: Destination unreachable.\n";
    else cout << "Minimum cost avoiding closed road: " << dist[B] << "\n";
}

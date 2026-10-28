/*
NEW EXAM VARIATION: Nearest of several starting stations
Change from teacher's code: Push all K sources with distance 0; report nearest source and cost to B.
Input example (enter the numbers in order, without this explanatory text):
5 5
1 3 4
2 3 1
3 5 2
1 4 2
4 5 5
2
1 2
5
Expected labeled output: Nearest source vertex: 2; Minimum cost to destination 5: 3
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000],origin[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void multi_source_dijkstra(const vector<int>& sources)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    for(int s:sources) // MAIN CHANGE: all sources start at cost zero
    { dist[s]=0; origin[s]=s; pq.push({0,s}); }
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w)
            { dist[v]=d+w; origin[v]=origin[u]; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int K;
    cout << "Enter number of starting stations: "; cin >> K;
    vector<int> sources(K);
    for(int i=0;i<K;i++)
    { cout << "Enter source vertex " << i+1 << ": "; cin >> sources[i]; }
    int B;
    cout << "Enter destination vertex: "; cin >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; origin[i]=-1; }
    multi_source_dijkstra(sources);
    if(dist[B]==100000000) cout << "Result: Destination unreachable.\n";
    else
    {
        cout << "Nearest source vertex: " << origin[B] << "\n";
        cout << "Minimum cost to destination " << B << ": " << dist[B] << "\n";
    }
}

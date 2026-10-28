/*
Package: warehouse to customer hub
Earlier code: Teacher Dijkstra -> earlier Tourist parent[] variation. Update dist and parent on relaxation.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 4 3
4 5 1
1 5
Expected labeled result:
Minimum shipping cost: 7; Hubs on path: 1 2 3 4 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <EDGE weight, neighbor vertex>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start}); // <best tentative distance, vertex>
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first, node=p.second;
        if(distance!=dist[node]) continue; // outdated heap entry
        for(auto it:adj[node])
        {
            int weight=it.first, neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // MAIN CHANGE: remember previous vertex
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of hubs (vertices) and routes (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter route " << i+1 << " as: from to shipping_cost: ";
        cin >> u >> v >> w; // edge u-v has weight w; no vertex weights
        adj[u].push_back({w,v});
        adj[v].push_back({w,u}); // undirected/two-way
    }
    int A,B;
    cout << "Enter starting vertex and destination vertex: ";
    cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A);
    if(dist[B]==100000000)
    {
        cout << "Result: Destination is unreachable.\n";
        return 0;
    }
    cout << "Minimum shipping cost: " << dist[B] << "\n";
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current); // destination to start
    reverse(path.begin(),path.end()); // now start to destination
    cout << "Hubs on path: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}

/*
NEW EXAM VARIATION: Directed roads and arbitrary source/destination
Change from teacher's code: Keep only adj[u].push_back; read A,B; output dist[B].
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 2
2 4 3
1 3 10
3 4 1
4 1 7
1 4
Expected labeled output: Minimum directed travel cost from 1 to 4: 5
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first,node=p.second;
        if(distance!=dist[node]) continue;
        for(auto it:adj[node])
        {
            int w=it.first,neighbor=it.second;
            if(dist[neighbor]>distance+w)
            {
                dist[neighbor]=distance+w;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed edge " << i+1 << " as: from to weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); // MAIN CHANGE: no reverse v->u edge
    }
    int A,B;
    cout << "Enter source and destination vertices: "; cin >> A >> B;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000)
        cout << "Result: Destination unreachable.\n";
    else
        cout << "Minimum directed travel cost from " << A << " to "
             << B << ": " << dist[B] << "\n";
}

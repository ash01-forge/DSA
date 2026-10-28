/*
NEW EXAM VARIATION: Prim with maximum heap for a Maximum Spanning Tree
Change from teacher's code: Use default max heap instead of min heap, and sum selected edge weights.
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled output: Maximum spanning tree total weight using Prim: 21
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <edge weight,neighbor>
bool prims_max(int start,int& total)
{
    priority_queue<pair<int,int>> pq; // MAIN CHANGE: max heap
    pq.push({0,start});
    total=0;
    int seen=0;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int weight=p.first,node=p.second;
        if(visited[node]) continue;
        visited[node]=true;
        total+=weight; // chosen edge, 0 for start
        seen++;
        for(auto it:adj[node])
            if(!visited[it.second]) pq.push(it);
    }
    return seen==n; // false means disconnected
}
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int total;
    if(!prims_max(1,total)) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum spanning tree total weight using Prim: " << total << "\n";
}

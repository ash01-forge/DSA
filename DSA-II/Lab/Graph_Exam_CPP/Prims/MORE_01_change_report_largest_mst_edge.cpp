/*
MORE EXAM VARIATION: Prim finds largest selected edge in a minimum spanning tree
Change from teacher's code: During each first visit, update max_edge instead of only returning total cost.
Input example (numbers only, entered in this order):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Largest edge weight selected by Prim MST: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <cost,neighbor>
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq; // min heap
    pq.push({0,1});
    int seen=0,max_edge=INT_MIN;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int w=p.first,u=p.second;
        if(visited[u]) continue;
        visited[u]=true; seen++;
        if(u!=1) max_edge=max(max_edge,w); // MAIN CHANGE: selected bottleneck
        for(auto it:adj[u])
            if(!visited[it.second]) pq.push(it);
    }
    if(seen!=n) cout << "Result: Cannot form a full MST.\n";
    else if(n==1) cout << "Result: No edge selected for one vertex.\n";
    else cout << "Largest edge weight selected by Prim MST: " << max_edge << "\n";
}

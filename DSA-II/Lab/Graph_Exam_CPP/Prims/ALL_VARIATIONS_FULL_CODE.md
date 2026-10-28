# Prims: 3 standalone variations

## NEW_01_change_maximum_spanning_total.cpp

```cpp
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
```

## NEW_02_change_print_selected_mst_edges.cpp

```cpp
/*
NEW EXAM VARIATION: Prim prints selected Minimum Spanning Tree edges
Change from teacher's code: Store parent inside heap items and print the chosen edge on first visit.
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Selected edges: 1-2 (1), 2-3 (2), 3-4 (3); Total MST cost: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <edge weight,neighbor>
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
    // <weight,vertex,parent>. tuple min heap keeps lowest weight first.
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;
    pq.push({0,1,-1});
    int total=0,seen=0;
    cout << "Selected MST edges:\n";
    while(!pq.empty())
    {
        auto item=pq.top(); pq.pop();
        int w=get<0>(item),node=get<1>(item),parent=get<2>(item);
        if(visited[node]) continue;
        visited[node]=true; seen++; total+=w;
        // MAIN CHANGE: parent tells us WHICH edge was selected.
        if(parent!=-1)
            cout << "Edge " << parent << "-" << node << " has cost " << w << "\n";
        for(auto it:adj[node])
            if(!visited[it.second]) pq.push({it.first,it.second,node});
    }
    if(seen!=n) cout << "Result: Graph disconnected; full MST does not exist.\n";
    else cout << "Total MST cost: " << total << "\n";
}
```

## MORE_01_change_report_largest_mst_edge.cpp

```cpp
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
```

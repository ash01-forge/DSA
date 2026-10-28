# Bellman_Ford: 7 standalone variations

## 01_banking_transaction_cost.cpp

```cpp
/*
Banking transfer/rebate network
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum transaction cost from source 1 to vertices 1..4: 0, 4, 2, 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
using namespace std;

int n,m,dist[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <edge weight,<from,to>>

void initialize(int source)
{
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[source]=0;
}

bool relax(int start,int finish,int weight)
{
    // Essential guard: an unreachable vertex cannot relax an edge.
    if(dist[start]==INF) return false;
    if(dist[finish]>dist[start]+weight)
    {
        dist[finish]=dist[start]+weight;
        return true;
    }
    return false;
}

bool bellman_ford()
{
    for(int i=0;i<n-1;i++) // shortest paths have at most n-1 edges
        for(auto edge:edges)
            relax(edge.second.first,edge.second.second,edge.first);

    // Improvement in one more round: negative cycle reachable from source.
    for(auto edge:edges)
        if(relax(edge.second.first,edge.second.second,edge.first))
            return true;
    return false;
}

int main()
{
    cout << "Enter number of organizations (vertices) and directed transfers (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed transfer " << i+1 << " as: from to net_cost: ";
        cin >> u >> v >> w; // negative edge weight is allowed
        edges.push_back({w,{u,v}}); // directed u -> v only
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    initialize(source);
    if(bellman_ford())
        cout << "Result: Negative cycle reachable from source vertex " << source << ".\n";
    else
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INF)
                cout << "Vertex " << i << " is unreachable from " << source << ".\n";
            else
                cout << "Minimum transaction cost from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}
```

## 02_ev_battery_usage.cpp

```cpp
/*
Electric vehicle battery network
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum battery usage from source 1 to vertices 1..4: 0, 4, 2, 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
using namespace std;

int n,m,dist[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <edge weight,<from,to>>

void initialize(int source)
{
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[source]=0;
}

bool relax(int start,int finish,int weight)
{
    // Essential guard: an unreachable vertex cannot relax an edge.
    if(dist[start]==INF) return false;
    if(dist[finish]>dist[start]+weight)
    {
        dist[finish]=dist[start]+weight;
        return true;
    }
    return false;
}

bool bellman_ford()
{
    for(int i=0;i<n-1;i++) // shortest paths have at most n-1 edges
        for(auto edge:edges)
            relax(edge.second.first,edge.second.second,edge.first);

    // Improvement in one more round: negative cycle reachable from source.
    for(auto edge:edges)
        if(relax(edge.second.first,edge.second.second,edge.first))
            return true;
    return false;
}

int main()
{
    cout << "Enter number of cities (vertices) and directed roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed road " << i+1 << " as: from to battery_consumption_or_recharge: ";
        cin >> u >> v >> w; // negative edge weight is allowed
        edges.push_back({w,{u,v}}); // directed u -> v only
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    initialize(source);
    if(bellman_ford())
        cout << "Result: Negative cycle reachable from source vertex " << source << ".\n";
    else
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INF)
                cout << "Vertex " << i << " is unreachable from " << source << ".\n";
            else
                cout << "Minimum battery usage from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}
```

## 03_game_resource_cost.cpp

```cpp
/*
Game milestone spending minus rewards
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum resource cost from source 1 to vertices 1..4: 0, 4, 2, 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
using namespace std;

int n,m,dist[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <edge weight,<from,to>>

void initialize(int source)
{
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[source]=0;
}

bool relax(int start,int finish,int weight)
{
    // Essential guard: an unreachable vertex cannot relax an edge.
    if(dist[start]==INF) return false;
    if(dist[finish]>dist[start]+weight)
    {
        dist[finish]=dist[start]+weight;
        return true;
    }
    return false;
}

bool bellman_ford()
{
    for(int i=0;i<n-1;i++) // shortest paths have at most n-1 edges
        for(auto edge:edges)
            relax(edge.second.first,edge.second.second,edge.first);

    // Improvement in one more round: negative cycle reachable from source.
    for(auto edge:edges)
        if(relax(edge.second.first,edge.second.second,edge.first))
            return true;
    return false;
}

int main()
{
    cout << "Enter number of milestones (vertices) and directed progression links (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed link " << i+1 << " as: from to spending_minus_reward: ";
        cin >> u >> v >> w; // negative edge weight is allowed
        edges.push_back({w,{u,v}}); // directed u -> v only
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    initialize(source);
    if(bellman_ford())
        cout << "Result: Negative cycle reachable from source vertex " << source << ".\n";
    else
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INF)
                cout << "Vertex " << i << " is unreachable from " << source << ".\n";
            else
                cout << "Minimum resource cost from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}
```

## NEW_01_change_negative_cycle_anywhere.cpp

```cpp
/*
NEW EXAM VARIATION: Detect a negative cycle anywhere in the directed graph
Change from teacher's code: Set every distance to zero, like connecting a super-source to all vertices.
Input example (enter the numbers in order, without this explanatory text):
4 3
1 2 5
3 4 -2
4 3 1
Expected labeled output: Negative cycle anywhere in graph: YES
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m,dist[1000];
vector<pair<int,pair<int,int>>> edges; // <weight,<from,to>>
bool negative_cycle_anywhere()
{
    // MAIN CHANGE: zero initialization reaches every component.
    for(int i=1;i<=n;i++) dist[i]=0;
    for(int round=1;round<=n;round++)
    {
        bool changed=false;
        for(auto edge:edges)
        {
            int w=edge.first,u=edge.second.first,v=edge.second.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                changed=true;
            }
        }
        if(!changed) return false;
        if(round==n && changed) return true; // nth round improvement
    }
    return false;
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
    cout << "Negative cycle anywhere in graph: "
         << (negative_cycle_anywhere() ? "YES" : "NO") << "\n";
}
```

## NEW_02_change_path_reconstruction.cpp

```cpp
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
```

## MORE_01_change_at_most_k_edges.cpp

```cpp
/*
MORE EXAM VARIATION: Cheapest route using at most K edges
Change from teacher's code: Relax for K rounds using a previous-round copy so one round adds one edge.
Input example (numbers only, entered in this order):
3 3
1 2 2
2 3 -5
1 3 1
1 3 2
Expected labeled output: Minimum cost using at most 2 edges: -3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
using namespace std;
struct Edge { int u,v,w; };
int n,m;
vector<Edge> edges;
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    int A,B,K;
    cout << "Enter source, destination, and maximum edge count K: ";
    cin >> A >> B >> K;
    const int INF=100000000;
    vector<int> previous(n+1,INF);
    previous[A]=0;
    for(int round=1;round<=K;round++)
    {
        vector<int> current=previous; // keep solutions using fewer edges
        for(Edge e:edges)
            if(previous[e.u]!=INF && current[e.v]>previous[e.u]+e.w)
                current[e.v]=previous[e.u]+e.w;
        // MAIN CHANGE: use previous, not current, for each relaxation round.
        previous=current;
    }
    if(previous[B]==INF) cout << "Result: No route within edge limit.\n";
    else cout << "Minimum cost using at most " << K
              << " edges: " << previous[B] << "\n";
}
```

## MORE_02_change_cycle_affects_destination.cpp

```cpp
/*
MORE EXAM VARIATION: Determine whether a negative cycle makes target cost unbounded
Change from teacher's code: After n-1 rounds, propagate improvable vertices through outgoing edges.
Input example (numbers only, entered in this order):
5 5
1 2 1
2 3 -2
3 2 1
3 4 2
1 5 5
1 4
Expected labeled output: Negative cycle can affect destination 4: YES
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge { int u,v,w; };
int n,m,dist[1000];
bool affected[1000];
vector<Edge> edges;
vector<int> adj[1000];
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
        adj[e.u].push_back(e.v); // direction matters
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    const int INF=100000000;
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[A]=0;
    for(int round=1;round<n;round++)
        for(Edge e:edges)
            if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w)
                dist[e.v]=dist[e.u]+e.w;
    queue<int> q;
    for(Edge e:edges)
        if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w && !affected[e.v])
        { affected[e.v]=true; q.push(e.v); }
    // MAIN CHANGE: any vertex reachable from an improvable vertex is affected.
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
            if(!affected[v]) { affected[v]=true; q.push(v); }
    }
    cout << "Negative cycle can affect destination " << B << ": "
         << (affected[B] ? "YES" : "NO") << "\n";
    if(!affected[B] && dist[B]==INF)
        cout << "Destination is unreachable from source.\n";
    else if(!affected[B])
        cout << "Finite minimum cost to destination: " << dist[B] << "\n";
}
```

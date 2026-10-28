# Kruskal: 12 standalone variations

## 01_min_tree_largest_edge.cpp

```cpp
/*
Largest edge in a Minimum Spanning Tree
Earlier code: Earlier Question 8; same as CT-2-A Problem 1.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
Expected labeled result:
Most expensive cable in the minimum-cost network: 6
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

vector<pair<int,pair<int,int>>> edges; // <edge weight,<vertex u,vertex v>>

int main()
{
    cout << "Enter number of towers (vertices) and possible cables (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter cable " << i+1 << " as: vertex_1 vertex_2 installation_cost: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.begin(),edges.end()); // minimum tree: ascending
    int answer=INT_MIN,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=max(answer,w); // largest SELECTED edge
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Most expensive cable in the minimum-cost network: " << answer << "\n";
}
```

## 02_max_tree_weakest_edge.cpp

```cpp
/*
Weakest edge in a Maximum Spanning Tree
Earlier code: Earlier Question 7; same as CT-2-A Problem 2.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
Expected labeled result:
Weakest link in the maximum-bandwidth backbone: 5 Gbps
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

vector<pair<int,pair<int,int>>> edges; // <edge weight,<vertex u,vertex v>>

int main()
{
    cout << "Enter number of data centers (vertices) and possible links (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter link " << i+1 << " as: vertex_1 vertex_2 bandwidth_Gbps: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // maximum tree: descending
    int answer=INT_MAX,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=min(answer,w); // weakest SELECTED edge
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Weakest link in the maximum-bandwidth backbone: " << answer << " Gbps\n";
}
```

## 03_max_truck_weight.cpp

```cpp
/*
Disaster Relief: maximum safe truck weight
Earlier code: Earlier Question 7; descending sort, minimum selected limit.
Input example (type the numbers in this order; prompts appear between entries):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled result:
Maximum truck weight that can reach every city: 6
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

vector<pair<int,pair<int,int>>> edges; // <edge weight,<vertex u,vertex v>>

int main()
{
    cout << "Enter number of cities (vertices) and roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: vertex_1 vertex_2 maximum_truck_weight: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // strongest road first
    int answer=INT_MAX,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=min(answer,w); // weakest road limits the truck
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum truck weight that can reach every city: " << answer << "\n";
}
```

## 04_fiber_existing_required.cpp

```cpp
/*
Minimum-cost fiber network with existing links and required cable
Earlier code: Teacher Kruskal: union existing links before sorting; pay for and union required edge.
Input example (type the numbers in this order; prompts appear between entries):
4 4 1
1 3 8
2 3 4
2 4 9
1 4 20
1 2
3 4 6
Expected labeled result:
Minimum total cable construction cost: 10
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

int k;
vector<pair<int,pair<int,int>>> edges; // <cost,<u,v>>
int main()
{
    cout << "Enter number of islands, optional cables, and existing connections: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1
             << " as: island_1 island_2 construction_cost: ";
        cin >> u >> v >> cost; // edge weight is cost
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v); // cost zero, already connected
    }
    int X,Y,required_cost;
    cout << "Enter required cable as: island_1 island_2 construction_cost: ";
    cin >> X >> Y >> required_cost;
    int total_cost=required_cost; // pay EVEN if endpoints already connected
    union_sets(X,Y);
    sort(edges.begin(),edges.end()); // cheaper optional edges first
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v)) total_cost+=cost;
    }
    int root=find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=root)
        {
            cout << "Result: Cannot connect all islands.\n";
            return 0;
        }
    cout << "Minimum total cable construction cost: " << total_cost << "\n";
}
```

## 05_budget_tower_count.cpp

```cpp
/*
Budgeted cable construction: one tower per remaining component
Earlier code: Teacher Kruskal: budget check before union, then count DSU roots.
Input example (type the numbers in this order; prompts appear between entries):
5 5 1 6
1 2 2
2 3 3
3 4 4
4 5 5
1 5 10
1 2
Expected labeled result:
Cable construction cost used: 3; Number of towers needed: 3
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

int k,B;
vector<pair<int,pair<int,int>>> edges; // <construction cost,<u,v>>
int main()
{
    cout << "Enter islands, optional cables, existing connections, and budget: ";
    cin >> n >> m >> k >> B; // B is a budget, not a vertex weight
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1 << " as: island_1 island_2 cost: ";
        cin >> u >> v >> cost;
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v);
    }
    sort(edges.begin(),edges.end()); // cheapest useful edges first
    int total_cost=0;
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(find(u)==find(v)) continue; // already same component
        if(total_cost+cost<=B) // check BEFORE spending
        {
            union_sets(u,v);
            total_cost+=cost;
        }
        else break; // sorted nonnegative costs; later edges cost at least as much
    }
    int towers=0;
    for(int i=1;i<=n;i++)
        if(find(i)==i) towers++; // one tower for each DSU component
    cout << "Cable construction cost used: " << total_cost << "\n";
    cout << "Number of towers needed: " << towers << "\n";
}
```

## 06_metro_prebuilt_max_bandwidth.cpp

```cpp
/*
Metro fiber: prebuilt 0-based indexed routes
Earlier code: Teacher Kruskal + prebuilt DSU unions; sort descending, include forced bandwidth in sum.
Input example (type the numbers in this order; prompts appear between entries):
5 6 1
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
4
Expected labeled result:
Total bandwidth of the selected backbone: 25 Gbps
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

struct Edge { int u,v,w; };
vector<Edge> original_edges,optional_edges;
bool forced[1000];
bool larger_weight(Edge a,Edge b) { return a.w>b.w; }

int main()
{
    int k;
    cout << "Enter number of hubs, candidate fiber, and already-built routes: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter route index " << i << " as: vertex_1 vertex_2 bandwidth_Gbps: ";
        cin >> e.u >> e.v >> e.w;
        original_edges.push_back(e); // preserve 0-based input indexes
    }
    initialize();
    int selected=0;
    int answer=0;
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter 0-based index of already-built route " << i+1 << ": ";
        cin >> index; // INDEX of an edge, NOT a vertex ID
        if(index<0 || index>=m || forced[index])
        {
            cout << "Result: Invalid or repeated route index.\n";
            return 0;
        }
        forced[index]=true;
        Edge e=original_edges[index];
        if(!union_sets(e.u,e.v))
        {
            cout << "Result: Forced routes create a cycle; no spanning tree exists.\n";
            return 0;
        }
        answer=answer+e.w; // forced edge's bandwidth/capacity MUST count
        selected++;
    }
    for(int i=0;i<m;i++)
        if(!forced[i]) optional_edges.push_back(original_edges[i]);
    sort(optional_edges.begin(),optional_edges.end(),larger_weight);
    for(Edge e:optional_edges)
        if(union_sets(e.u,e.v))
        {
            answer=answer+e.w; // add only edges joining components
            selected++;
        }
    if(selected!=n-1)
        cout << "Result: Cannot connect all vertices into a spanning tree.\n";
    else
        cout << "Total bandwidth of the selected backbone: " << answer << " Gbps\n";
}
```

## 07_rail_mandatory_weakest.cpp

```cpp
/*
Rail corridors: mandatory 0-based indexed routes
Earlier code: Teacher max Kruskal, force indexed edges before sort, min over ALL selected capacities.
Input example (type the numbers in this order; prompts appear between entries):
5 6 1
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
0
Expected labeled result:
Weakest capacity among selected corridors: 3
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // same DSU style as teacher
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false; // cycle
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}

struct Edge { int u,v,w; };
vector<Edge> original_edges,optional_edges;
bool forced[1000];
bool larger_weight(Edge a,Edge b) { return a.w>b.w; }

int main()
{
    int k;
    cout << "Enter number of towns, candidate rail, and mandatory routes: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter route index " << i << " as: vertex_1 vertex_2 passenger_capacity: ";
        cin >> e.u >> e.v >> e.w;
        original_edges.push_back(e); // preserve 0-based input indexes
    }
    initialize();
    int selected=0;
    int answer=INT_MAX;
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter 0-based index of mandatory route " << i+1 << ": ";
        cin >> index; // INDEX of an edge, NOT a vertex ID
        if(index<0 || index>=m || forced[index])
        {
            cout << "Result: Invalid or repeated route index.\n";
            return 0;
        }
        forced[index]=true;
        Edge e=original_edges[index];
        if(!union_sets(e.u,e.v))
        {
            cout << "Result: Forced routes create a cycle; no spanning tree exists.\n";
            return 0;
        }
        answer=min(answer,e.w); // forced edge's bandwidth/capacity MUST count
        selected++;
    }
    for(int i=0;i<m;i++)
        if(!forced[i]) optional_edges.push_back(original_edges[i]);
    sort(optional_edges.begin(),optional_edges.end(),larger_weight);
    for(Edge e:optional_edges)
        if(union_sets(e.u,e.v))
        {
            answer=min(answer,e.w); // add only edges joining components
            selected++;
        }
    if(selected!=n-1)
        cout << "Result: Cannot connect all vertices into a spanning tree.\n";
    else
        cout << "Weakest capacity among selected corridors: " << answer << "\n";
}
```

## NEW_01_change_maximum_total_weight.cpp

```cpp
/*
NEW EXAM VARIATION: Maximum Spanning Tree total weight
Change from teacher's code: Sort descending and SUM selected edge weights (rather than taking min edge).
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled output: Maximum spanning tree total weight: 21
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges; // <weight,<u,v>>
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // MAIN CHANGE: largest edge first
    int total=0,taken=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
        { total+=edge.first; taken++; } // sum, not weakest edge
    if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum spanning tree total weight: " << total << "\n";
}
```

## NEW_02_change_existing_free_links_no_mandatory.cpp

```cpp
/*
NEW EXAM VARIATION: Minimum additional cost with existing free links
Change from teacher's code: Union K existing pairs first; then run ascending Kruskal, without a required cable.
Input example (enter the numbers in order, without this explanatory text):
4 4 1
1 3 8
2 3 4
2 4 9
3 4 6
1 2
Expected labeled output: Minimum additional construction cost: 10
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges; // <cost,<u,v>>
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter vertices, candidate edges, and existing free connections: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter candidate edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> cost;
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter free existing connection " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v); // MAIN CHANGE: free connectivity before Kruskal
    }
    sort(edges.begin(),edges.end());
    int total=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
            total+=edge.first;
    int root=find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=root)
        { cout << "Result: Cannot connect all vertices.\n"; return 0; }
    cout << "Minimum additional construction cost: " << total << "\n";
}
```

## NEW_03_change_stop_at_k_components.cpp

```cpp
/*
NEW EXAM VARIATION: Minimum-cost grouping into exactly K connected components
Change from teacher's code: Run ascending Kruskal and stop when component count reaches K.
Input example (enter the numbers in order, without this explanatory text):
5 5 2
1 2 1
2 3 2
3 4 3
4 5 4
1 5 10
Expected labeled output: Minimum cost to form 2 groups: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,K,_parent[1000],_rank[1000],components;
vector<pair<int,pair<int,int>>> edges;
void initialize()
{ components=n; for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    components--; // count connected groups
    return true;
}
int main()
{
    cout << "Enter vertices, edges, and desired number of groups K: ";
    cin >> n >> m >> K;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    if(K<1 || K>n) { cout << "Result: Invalid K.\n"; return 0; }
    initialize();
    sort(edges.begin(),edges.end());
    int total=0;
    for(auto edge:edges)
    {
        if(components==K) break; // MAIN CHANGE: stop before full MST
        if(union_sets(edge.second.first,edge.second.second))
            total+=edge.first;
    }
    if(components!=K) cout << "Result: Cannot form exactly K groups.\n";
    else cout << "Minimum cost to form " << K << " groups: " << total << "\n";
}
```

## MORE_01_change_total_savings.cpp

```cpp
/*
MORE EXAM VARIATION: Savings after replacing all roads with an MST
Change from teacher's code: Sum all edge costs and subtract minimum spanning tree cost.
Input example (numbers only, entered in this order):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Total original cost: 15; Minimum network cost: 6; Savings: 9
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges;
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    return true;
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    int original_total=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
        original_total+=w; // cost of ALL input edges
    }
    initialize(); sort(edges.begin(),edges.end());
    int mst_cost=0,taken=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
        { mst_cost+=edge.first; taken++; }
    if(taken!=n-1) { cout << "Result: Full network impossible.\n"; return 0; }
    // MAIN CHANGE: compare original total with selected MST edges.
    cout << "Total original cost: " << original_total << "\n";
    cout << "Minimum network cost: " << mst_cost << "\n";
    cout << "Savings: " << original_total-mst_cost << "\n";
}
```

## MORE_02_change_forbidden_edge_indices.cpp

```cpp
/*
MORE EXAM VARIATION: MST with certain routes forbidden by 0-based index
Change from teacher's code: Exclude forbidden indexes before sorting optional edges.
Input example (numbers only, entered in this order):
4 5 1
1 2 1
2 3 2
3 4 3
1 4 10
1 3 4
1
Expected labeled output: Minimum spanning tree cost avoiding forbidden routes: 8
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,_parent[1000],_rank[1000];
bool forbidden[1000];
vector<pair<int,pair<int,int>>> original,allowed;
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    return true;
}
int main()
{
    cout << "Enter vertices, routes, and forbidden route count: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter route at 0-based index " << i
             << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        original.push_back({w,{u,v}});
    }
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter forbidden 0-based route index " << i+1 << ": ";
        cin >> index; // edge index, not vertex ID
        if(index<0 || index>=m)
        { cout << "Result: Invalid route index.\n"; return 0; }
        forbidden[index]=true;
    }
    for(int i=0;i<m;i++)
        if(!forbidden[i]) allowed.push_back(original[i]); // MAIN CHANGE
    initialize(); sort(allowed.begin(),allowed.end());
    int total=0,taken=0;
    for(auto edge:allowed)
        if(union_sets(edge.second.first,edge.second.second))
        { total+=edge.first; taken++; }
    if(taken!=n-1) cout << "Result: No permitted spanning tree.\n";
    else cout << "Minimum spanning tree cost avoiding forbidden routes: "
              << total << "\n";
}
```

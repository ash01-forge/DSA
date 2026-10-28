# DSU: 5 standalone variations

## 01_corporate_merge_query.cpp

```cpp
/*
Corporate MERGE / QUERY operations
Earlier code: Teacher Kruskal DSU functions; remove edge sorting and MST cost.
Input example (type the numbers in this order; prompts appear between entries):
5 6
MERGE 1 2
QUERY 1 3
MERGE 2 3
QUERY 1 3
QUERY 4 5
MERGE 4 5
Expected labeled result:
Query 1,3: NO; Query 1,3: YES; Query 4,5: NO
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<string>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // teacher's find (no path compression)
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter number of companies and operations: ";
    cin >> n >> m; // m is operation count, not edge count
    initialize();
    for(int i=0;i<m;i++)
    {
        string operation; int A,B;
        cout << "Enter operation " << i+1 << " as MERGE A B or QUERY A B: ";
        cin >> operation >> A >> B;
        if(operation=="MERGE")
        {
            union_sets(A,B); // merge groups; no weights
            cout << "Merge completed for companies " << A << " and " << B << ".\n";
        }
        else if(operation=="QUERY")
        {
            cout << "Connection result for companies " << A << " and " << B
                 << ": " << (find(A)==find(B) ? "YES" : "NO") << "\n";
        }
    }
}
```

## NEW_01_change_component_count_and_size.cpp

```cpp
/*
NEW EXAM VARIATION: Report number of groups and size of a queried group
Change from teacher's code: Store size at each root; decrease component count after a successful union.
Input example (enter the numbers in order, without this explanatory text):
5 3
1 2
2 3
4 5
2
Expected labeled output: Number of connected groups: 2; Size of group containing 2: 3
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000],group_size[1000],components;
void initialize()
{
    components=n;
    for(int i=1;i<=n;i++)
    { _parent[i]=i; _rank[i]=0; group_size[i]=1; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]);
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]<_rank[rooty]) swap(rootx,rooty);
    _parent[rooty]=rootx;
    group_size[rootx]+=group_size[rooty]; // MAIN CHANGE: combine sizes
    if(_rank[rootx]==_rank[rooty]) _rank[rootx]++;
    components--; // two groups become one
    return true;
}
int main()
{
    cout << "Enter number of vertices and connections: "; cin >> n >> m;
    initialize();
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "Enter connection " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v); // no edge/vertex weights
    }
    int x;
    cout << "Enter vertex whose group size you want: "; cin >> x;
    cout << "Number of connected groups: " << components << "\n";
    cout << "Size of group containing " << x << ": "
         << group_size[find(x)] << "\n";
}
```

## NEW_02_change_detect_undirected_cycle.cpp

```cpp
/*
NEW EXAM VARIATION: Check whether an undirected graph has a cycle
Change from teacher's code: If union_sets(u,v) returns false, this edge closes a cycle.
Input example (enter the numbers in order, without this explanatory text):
3 3
1 2
2 3
1 3
Expected labeled output: Cycle detected in undirected graph: YES
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
using namespace std;
int n,m,_parent[1000],_rank[1000];
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
    cout << "Enter vertices and undirected edges: "; cin >> n >> m;
    initialize();
    bool cycle=false;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        if(!union_sets(u,v)) cycle=true; // MAIN CHANGE: same-root edge creates cycle
    }
    cout << "Cycle detected in undirected graph: "
         << (cycle ? "YES" : "NO") << "\n";
}
```

## MORE_01_change_first_step_all_connected.cpp

```cpp
/*
MORE EXAM VARIATION: Earliest operation when every vertex becomes connected
Change from teacher's code: Track component count after each union and stop at one.
Input example (numbers only, entered in this order):
4 4
1 2
3 4
2 3
1 4
Expected labeled output: First operation connecting all vertices: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
using namespace std;
int n,m,_parent[1000],_rank[1000],components;
void initialize()
{ components=n; for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    components--; // MAIN CHANGE: count groups after each event
    return true;
}
int main()
{
    cout << "Enter vertices and chronological connection events: "; cin >> n >> m;
    initialize();
    int first=(n==1 ? 0 : -1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cout << "Enter connection event " << i << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v);
        if(components==1 && first==-1) first=i;
    }
    if(first==-1) cout << "Result: Never fully connected.\n";
    else cout << "First operation connecting all vertices: " << first << "\n";
}
```

## MORE_02_change_dynamic_size_and_count_queries.cpp

```cpp
/*
MORE EXAM VARIATION: Dynamic MERGE, SIZE, and COUNT commands
Change from teacher's code: Store component sizes and count while processing mixed operations.
Input example (numbers only, entered in this order):
4 5
MERGE 1 2
SIZE 2
COUNT
MERGE 2 3
SIZE 3
Expected labeled output: Size of group containing 2: 2; Number of groups: 3; Size of group containing 3: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000],group_size[1000],components;
void initialize()
{
    components=n;
    for(int i=1;i<=n;i++)
    { _parent[i]=i; _rank[i]=0; group_size[i]=1; }
}
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
void union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return;
    if(_rank[a]<_rank[b]) swap(a,b);
    _parent[b]=a;
    group_size[a]+=group_size[b];
    if(_rank[a]==_rank[b]) _rank[a]++;
    components--;
}
int main()
{
    cout << "Enter vertices and number of operations: "; cin >> n >> m;
    initialize();
    for(int i=0;i<m;i++)
    {
        string op;
        cout << "Enter operation " << i+1 << " (MERGE A B, SIZE A, or COUNT): ";
        cin >> op;
        if(op=="MERGE")
        {
            int A,B; cin >> A >> B; // two vertex IDs
            union_sets(A,B);
            cout << "Merged groups of " << A << " and " << B << ".\n";
        }
        else if(op=="SIZE")
        {
            int A; cin >> A;
            cout << "Size of group containing " << A << ": "
                 << group_size[find(A)] << "\n";
        }
        else if(op=="COUNT")
            cout << "Number of groups: " << components << "\n";
    }
}
```

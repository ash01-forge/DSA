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

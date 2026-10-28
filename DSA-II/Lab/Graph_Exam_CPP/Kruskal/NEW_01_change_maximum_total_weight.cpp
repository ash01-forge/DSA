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

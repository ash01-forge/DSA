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

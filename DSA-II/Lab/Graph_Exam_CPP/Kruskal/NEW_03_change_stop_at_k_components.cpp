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

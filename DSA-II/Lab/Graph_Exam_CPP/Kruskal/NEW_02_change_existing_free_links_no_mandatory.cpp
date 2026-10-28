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

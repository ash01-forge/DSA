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

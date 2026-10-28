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

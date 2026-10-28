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

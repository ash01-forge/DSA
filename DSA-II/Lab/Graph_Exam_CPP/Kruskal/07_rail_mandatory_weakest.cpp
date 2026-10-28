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

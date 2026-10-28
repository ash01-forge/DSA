/*
Minimum-cost fiber network with existing links and required cable
Earlier code: Teacher Kruskal: union existing links before sorting; pay for and union required edge.
Input example (type the numbers in this order; prompts appear between entries):
4 4 1
1 3 8
2 3 4
2 4 9
1 4 20
1 2
3 4 6
Expected labeled result:
Minimum total cable construction cost: 10
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
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

int k;
vector<pair<int,pair<int,int>>> edges; // <cost,<u,v>>
int main()
{
    cout << "Enter number of islands, optional cables, and existing connections: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1
             << " as: island_1 island_2 construction_cost: ";
        cin >> u >> v >> cost; // edge weight is cost
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v); // cost zero, already connected
    }
    int X,Y,required_cost;
    cout << "Enter required cable as: island_1 island_2 construction_cost: ";
    cin >> X >> Y >> required_cost;
    int total_cost=required_cost; // pay EVEN if endpoints already connected
    union_sets(X,Y);
    sort(edges.begin(),edges.end()); // cheaper optional edges first
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v)) total_cost+=cost;
    }
    int root=find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=root)
        {
            cout << "Result: Cannot connect all islands.\n";
            return 0;
        }
    cout << "Minimum total cable construction cost: " << total_cost << "\n";
}

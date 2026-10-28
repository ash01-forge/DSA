/*
Budgeted cable construction: one tower per remaining component
Earlier code: Teacher Kruskal: budget check before union, then count DSU roots.
Input example (type the numbers in this order; prompts appear between entries):
5 5 1 6
1 2 2
2 3 3
3 4 4
4 5 5
1 5 10
1 2
Expected labeled result:
Cable construction cost used: 3; Number of towers needed: 3
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

int k,B;
vector<pair<int,pair<int,int>>> edges; // <construction cost,<u,v>>
int main()
{
    cout << "Enter islands, optional cables, existing connections, and budget: ";
    cin >> n >> m >> k >> B; // B is a budget, not a vertex weight
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1 << " as: island_1 island_2 cost: ";
        cin >> u >> v >> cost;
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v);
    }
    sort(edges.begin(),edges.end()); // cheapest useful edges first
    int total_cost=0;
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(find(u)==find(v)) continue; // already same component
        if(total_cost+cost<=B) // check BEFORE spending
        {
            union_sets(u,v);
            total_cost+=cost;
        }
        else break; // sorted nonnegative costs; later edges cost at least as much
    }
    int towers=0;
    for(int i=1;i<=n;i++)
        if(find(i)==i) towers++; // one tower for each DSU component
    cout << "Cable construction cost used: " << total_cost << "\n";
    cout << "Number of towers needed: " << towers << "\n";
}

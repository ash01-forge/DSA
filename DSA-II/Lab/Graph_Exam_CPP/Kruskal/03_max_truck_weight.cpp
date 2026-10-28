/*
Disaster Relief: maximum safe truck weight
Earlier code: Earlier Question 7; descending sort, minimum selected limit.
Input example (type the numbers in this order; prompts appear between entries):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled result:
Maximum truck weight that can reach every city: 6
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

vector<pair<int,pair<int,int>>> edges; // <edge weight,<vertex u,vertex v>>

int main()
{
    cout << "Enter number of cities (vertices) and roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: vertex_1 vertex_2 maximum_truck_weight: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // strongest road first
    int answer=INT_MAX,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=min(answer,w); // weakest road limits the truck
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum truck weight that can reach every city: " << answer << "\n";
}

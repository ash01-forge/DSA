/*
Largest edge in a Minimum Spanning Tree
Earlier code: Earlier Question 8; same as CT-2-A Problem 1.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
Expected labeled result:
Most expensive cable in the minimum-cost network: 6
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
    cout << "Enter number of towers (vertices) and possible cables (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter cable " << i+1 << " as: vertex_1 vertex_2 installation_cost: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.begin(),edges.end()); // minimum tree: ascending
    int answer=INT_MIN,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=max(answer,w); // largest SELECTED edge
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Most expensive cable in the minimum-cost network: " << answer << "\n";
}

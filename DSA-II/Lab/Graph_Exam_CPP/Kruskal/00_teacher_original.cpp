#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// DSU
int _parent[1000];
int _rank[1000];
int n;
int m;

void initialize(){
    for(int i=0;i<=n;i++)
    {
        _parent[i]=i;
        _rank[i]=0;
    }
}
int find(int x) // find the root
{
    if(_parent[x]==x)
        return x;
    else 
        return find(_parent[x]);

}
// if returns true--> union possible--> root not same --> no cycle --> then that edge is in MST. otherwise not. 
bool union_sets(int x,int y)
{
    int rootx=find(x);
    int rooty=find(y);
    if(rootx!=rooty)
    {
        // union possible
        if(_rank[rootx]==_rank[rooty])
        {
            // tie --> randomly choose a node (rootx) and make parent
            _parent[rooty]=rootx;
            _rank[rootx]++;
        }
        else if(_rank[rootx]>_rank[rooty])
            _parent[rooty]=rootx;
        else
            _parent[rootx]=rooty;

        return true;
    }

    return false;

}

/// MST
// edge list (not adjacency list)


/// pair<weight,pair<start_node, end_node>>
/// weight is in front, because by default a vector is sorted based on the first element
/// in this case, it is weight
vector<pair<int,pair<int,int>>> edges;



int main()
{
    cin>>n>>m; /// n=node, m=edges
    for(int i=0;i<m;i++)
    {
        int start, end, weight;
        cin>>start>>end>>weight;
        edges.push_back({weight,{start, end}});
    }

    /// sort the edge list
    sort(edges.begin(), edges.end());

    /// choose edges one by one
    initialize(); /// init the DSU
    int cost=0;
    for(int i=0;i<m;i++)
    {
        int weight=edges[i].first;
        int start=edges[i].second.first;
        int end=edges[i].second.second;
        if(union_sets(start,end)==true) /// union possible, no cycle, in the MST
        {
            cost+=weight; // taken in code
        }

    }
    cout<<cost<<endl;


}
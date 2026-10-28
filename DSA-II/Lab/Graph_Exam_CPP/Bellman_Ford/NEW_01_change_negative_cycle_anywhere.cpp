/*
NEW EXAM VARIATION: Detect a negative cycle anywhere in the directed graph
Change from teacher's code: Set every distance to zero, like connecting a super-source to all vertices.
Input example (enter the numbers in order, without this explanatory text):
4 3
1 2 5
3 4 -2
4 3 1
Expected labeled output: Negative cycle anywhere in graph: YES
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m,dist[1000];
vector<pair<int,pair<int,int>>> edges; // <weight,<from,to>>
bool negative_cycle_anywhere()
{
    // MAIN CHANGE: zero initialization reaches every component.
    for(int i=1;i<=n;i++) dist[i]=0;
    for(int round=1;round<=n;round++)
    {
        bool changed=false;
        for(auto edge:edges)
        {
            int w=edge.first,u=edge.second.first,v=edge.second.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                changed=true;
            }
        }
        if(!changed) return false;
        if(round==n && changed) return true; // nth round improvement
    }
    return false;
}
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed edge " << i+1 << " as: from to signed_weight: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    cout << "Negative cycle anywhere in graph: "
         << (negative_cycle_anywhere() ? "YES" : "NO") << "\n";
}

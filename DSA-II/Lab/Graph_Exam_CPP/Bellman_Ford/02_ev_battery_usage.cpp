/*
Electric vehicle battery network
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum battery usage from source 1 to vertices 1..4: 0, 4, 2, 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
using namespace std;

int n,m,dist[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <edge weight,<from,to>>

void initialize(int source)
{
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[source]=0;
}

bool relax(int start,int finish,int weight)
{
    // Essential guard: an unreachable vertex cannot relax an edge.
    if(dist[start]==INF) return false;
    if(dist[finish]>dist[start]+weight)
    {
        dist[finish]=dist[start]+weight;
        return true;
    }
    return false;
}

bool bellman_ford()
{
    for(int i=0;i<n-1;i++) // shortest paths have at most n-1 edges
        for(auto edge:edges)
            relax(edge.second.first,edge.second.second,edge.first);

    // Improvement in one more round: negative cycle reachable from source.
    for(auto edge:edges)
        if(relax(edge.second.first,edge.second.second,edge.first))
            return true;
    return false;
}

int main()
{
    cout << "Enter number of cities (vertices) and directed roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed road " << i+1 << " as: from to battery_consumption_or_recharge: ";
        cin >> u >> v >> w; // negative edge weight is allowed
        edges.push_back({w,{u,v}}); // directed u -> v only
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    initialize(source);
    if(bellman_ford())
        cout << "Result: Negative cycle reachable from source vertex " << source << ".\n";
    else
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INF)
                cout << "Vertex " << i << " is unreachable from " << source << ".\n";
            else
                cout << "Minimum battery usage from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}

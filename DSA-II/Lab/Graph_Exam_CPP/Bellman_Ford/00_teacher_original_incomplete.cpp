#include <iostream>
#include <vector>
using namespace std;
int node_count;
int dist[1000];
int parent[1000];
/// vector<pair<WEIGHT,pair<START,END>>> edges;
vector<pair<int, pair<int, int>>> edges;

void initialize(int source)
{
    for (int i = 0; i <= node_count; i++)
        dist[i] = 100000000; /// max value (problem is to minimize the distance)
    dist[source] = 0;
    for (int i = 0; i <= node_count; i++)
        parent[i] = i;
}

/// for every edge, if relaxed/distance changed, then true. otherwise false
bool relax(int start, int _end, int weight)
{
    if (dist[_end] > dist[start] + weight)
    {
        dist[_end] = dist[start] + weight; /// relax / distance reduce
        /// if a distance is updated, we need to update the parent
        parent[_end] = start;
        return true; /// relaxed
    }

    return false; /// not relaxed
}

void bellman_ford()
{
    for (int i = 0; i < node_count - 1; i++) /// run this loop for node_count-1 times
    {
        for (auto edge : edges) /// relax every edge
        {
            int start = edge.second.first;
            int _end = edge.second.second;
            int weight = edge.first;
            relax(start, _end, weight);
        }
    }

    /// do it one more time to check for negative cycle
    bool is_negCycle = false;
    for (auto edge : edges) /// relax every edge
    {
        int start = edge.second.first;
        int _end = edge.second.second;
        int weight = edge.first;
        if (relax(start, _end, weight) == true) /// relaxed. so there is a negative cycle.
            is_negCycle = true;
    }
    if (is_negCycle == true)
        cout << " there is a negative cycle " << endl;
}

/// reconstruct the path from node i(destination) to start
void path_reconstruction(int i)
{
    cout << i << " ";   /// at first, print the current node
    if (parent[i] == i) /// found the source, stop
        return;
    else
        path_reconstruction(parent[i]); /// recursive call to parent
}

int main()
{
    int m; // edge count
    cin >> node_count >> m;
    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v});
            /// if it is an undirected graph
                        edges.push_back({w,{v,u}); /// comment this line if directed
                                       }


                       }

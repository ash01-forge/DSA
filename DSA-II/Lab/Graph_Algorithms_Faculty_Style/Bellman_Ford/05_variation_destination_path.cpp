#include "bellman_common.h"
/// VARIATION: One destination-এর minimum distance ও parent path।
/// CHANGE: all distances-এর বদলে destination output এবং reverse reconstruction।
int main()
{
    int m;
    ask("Enter nodes and directed edges: N M");
    cin >> node_count >> m;
    read_edges(m, "weight");
    int s, d;
    ask("Enter source and destination:");
    cin >> s >> d;
    initialize(s);
    bellman_ford();
    if (is_negCycle)
    {
        cout << "There is a negative cycle" << endl;
        return 0;
    }
    label("Minimum distance: ");
    cout << dist[d] << endl;
    vector<int> path;
    int node = d;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);
    label("Path: ");
    for (int i = (int)path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}
/* INPUT: N M; M directed edges; source destination. OUTPUT: cycle or distance+path. */

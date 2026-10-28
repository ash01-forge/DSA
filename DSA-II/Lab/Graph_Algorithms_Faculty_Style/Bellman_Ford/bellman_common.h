#include <iostream>
#include <vector>
#include <string>
using namespace std;
const bool SHOW_PROMPTS = true;
const int INF = 100000000;
int node_count, dist[1000], parent[1000];
bool is_negCycle;
vector<pair<int, pair<int, int>>> edges;
void ask(string s)
{
    if (SHOW_PROMPTS)
        cout << s << endl;
}
void label(string s)
{
    if (SHOW_PROMPTS)
        cout << s;
}
void initialize(int source)
{
    for (int i = 0; i <= node_count; i++)
    {
        dist[i] = INF;
        parent[i] = i;
    }
    dist[source] = 0;
}
bool relax(int start, int _end, int weight)
{
    if (dist[_end] > dist[start] + weight)
    {
        dist[_end] = dist[start] + weight;
        parent[_end] = start;
        return true;
    }
    return false;
}
void bellman_ford()
{
    for (int i = 0; i < node_count - 1; i++)
        for (auto e : edges)
            relax(e.second.first, e.second.second, e.first);
    is_negCycle = false;
    for (auto e : edges)
        if (relax(e.second.first, e.second.second, e.first))
            is_negCycle = true;
}
void read_edges(int m, string name)
{
    ask("Enter m directed edges: start end " + name);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
}
void print_dist()
{
    label("Minimum values to nodes 1..N: ");
    for (int i = 1; i <= node_count; i++)
        cout << dist[i] << " ";
    cout << endl;
}

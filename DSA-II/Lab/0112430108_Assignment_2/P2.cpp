#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 4271;

int n;
int m;

bool visited[MAX_N + 1];
vector<pair<int, int>> adj[MAX_N + 1];

int dist[MAX_N + 1];
int proc_delay[MAX_N + 1];

void pc_Relay(int start)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int distance = p.first;
        int node = p.second;

        if (visited[node] == false)
        {
            visited[node] = true;
            dist[node] = distance;
        }

        for (auto it : adj[node])
        {
            int weight = it.first;
            int neighbor = it.second;

            int neighbour_distance =
                distance + weight + proc_delay[neighbor];

            if (visited[neighbor] == false)
            {
                pq.push(
                    {neighbour_distance,
                     neighbor});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int start, _end, weight;
        cin >> start >> _end >> weight;

        adj[start].push_back(
            {weight,
             _end});

        adj[_end].push_back(
            {weight,
             start});
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> proc_delay[i];
    }

    for (int i = 0; i <= n; i++)
    {
        dist[i] = 100000000;
    }

    pc_Relay(1);

    cout << dist[n] << endl;
}
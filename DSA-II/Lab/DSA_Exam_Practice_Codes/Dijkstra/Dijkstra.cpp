#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; // node
int m; // edge
/// adj[x] means a list of pairs: <weight, neighbor>. adj[x]= [<1,y>, <3,z>......] [ y and z are neighbor of x]

bool visited[1000];
vector<pair<int, int>> adj[1000];

/// extra array = distance
int dist[1000];

/// we do not need the cost, just save distances in the distance array
void dijkstra(int start) /// a starting node
{
    /// need min heap

    // priority_queue<pair<int,int>> pq; /// max-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    /// initially, keep the start node inside min-heap
    pq.push({0, start});
    while (!pq.empty()) // run till pq is empty
    {
        /// extract --> visit that node --> push neighbors (a loop)

        pair<int, int> p = pq.top(); /// extract
        pq.pop();
        int distance = p.first; // CHANGE: DISTANCE INSTEAD OF WEIGHT
        int node = p.second;
        /// visit
        if (visited[node] == false)
        {
            visited[node] = true;
            dist[node] = distance; /// CHANGE: SAVE THE DISTANCE IN THE ARRAY
        }
        /// push neighbors
        for (auto it : adj[node]) /// visit the adjacency/neighbor list of that node
        {
            // "it" is a pair in the adjacency list of node. one by one, visit every pair using loop
            int weight = it.first;
            int neighbour_distance = weight + distance; /// extra
            int neighbor = it.second;
            if (visited[neighbor] == false)
            {
                // ***CHANGE****: push <DISTANCE, NEIGHBOR>
                pq.push({neighbour_distance, neighbor});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        adj[start].push_back({weight, end});
        adj[end].push_back({weight, start});
    }
    /// extra
    for (int i = 0; i <= n; i++)
    {
        dist[i] = 100000000;
    }

    /// starting node 1
    dijkstra(1);
    // THOUGH WE ARE SAVING SHORTEST PATH COST FOR EVERY NODE, QUESTION ASKED ONLY FOR n
    cout << dist[n] << endl;
}
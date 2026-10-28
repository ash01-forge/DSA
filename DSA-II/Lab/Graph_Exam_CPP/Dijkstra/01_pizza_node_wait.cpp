/*
Pizza Delivery: edge travel time plus vertex waiting time
Earlier code: Teacher Dijkstra; change heap key to distance + road time + wait[neighbor].
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 3
2 4 5
1 3 2
3 4 10
0 4 1 2
Expected labeled result:
Minimum delivery time from intersection 1 to intersection 4: 14 minutes
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
bool visited[1000];
int dist[1000], wait_time[1000]; // wait_time is a VERTEX weight
vector<pair<int,int>> adj[1000]; // <EDGE weight, neighbor vertex>

void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,
                   greater<pair<int,int>>> pq; // min heap <time, vertex>
    pq.push({0,start}); // no wait at the starting vertex
    while(!pq.empty())
    {
        pair<int,int> p = pq.top(); pq.pop();
        int distance = p.first, node = p.second;
        if(visited[node]) continue; // ignore duplicate heap entries
        visited[node] = true;
        dist[node] = distance;
        for(auto it : adj[node])
        {
            int road_time = it.first, neighbor = it.second;
            if(!visited[neighbor])
            {
                // MAIN CHANGE: entering neighbor adds its vertex waiting time.
                int new_distance = distance + road_time + wait_time[neighbor];
                pq.push({new_distance,neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of intersections (vertices) and roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: start end driving_minutes: ";
        cin >> u >> v >> w; // edge u-v has weight w
        adj[u].push_back({w,v});
        adj[v].push_back({w,u}); // two-way road
    }
    for(int i=1;i<=n;i++)
    {
        cout << "Enter waiting minutes at intersection " << i << ": ";
        cin >> wait_time[i]; // vertex i has this weight
        dist[i] = 100000000;
    }
    dijkstra(1);
    if(dist[n] == 100000000)
        cout << "Delivery result: Destination unreachable.\n";
    else
        cout << "Minimum delivery time from intersection 1 to intersection "
             << n << ": " << dist[n] << " minutes\n";
}

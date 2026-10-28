# All variation codes — complete source

Every block is a full standalone `.cpp` source file. Teacher originals remain unchanged.

# Dijkstra: 13 standalone variations

## 01_pizza_node_wait.cpp

```cpp
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
```

## 01_tourist_path.cpp

```cpp
/*
Tourist: shortest time and bus stops
Earlier code: Teacher Dijkstra -> earlier Tourist parent[] variation. Update dist and parent on relaxation.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 2
2 5 3
1 3 1
3 4 1
4 5 10
2 3 5
1 5
Expected labeled result:
Minimum travel time: 5 minutes; Stops on shortest route: 1 2 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <EDGE weight, neighbor vertex>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start}); // <best tentative distance, vertex>
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first, node=p.second;
        if(distance!=dist[node]) continue; // outdated heap entry
        for(auto it:adj[node])
        {
            int weight=it.first, neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // MAIN CHANGE: remember previous vertex
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of bus stops (vertices) and connections (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter connection " << i+1 << " as: from to travel_minutes: ";
        cin >> u >> v >> w; // edge u-v has weight w; no vertex weights
        adj[u].push_back({w,v});
        adj[v].push_back({w,u}); // undirected/two-way
    }
    int A,B;
    cout << "Enter starting vertex and destination vertex: ";
    cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A);
    if(dist[B]==100000000)
    {
        cout << "Result: Destination is unreachable.\n";
        return 0;
    }
    cout << "Minimum travel time: " << dist[B] << " minutes\n";
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current); // destination to start
    reverse(path.begin(),path.end()); // now start to destination
    cout << "Stops on shortest route: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}
```

## 02_ambulance_path.cpp

```cpp
/*
Ambulance: hospital to accident site
Earlier code: Teacher Dijkstra -> earlier Tourist parent[] variation. Update dist and parent on relaxation.
Input example (type the numbers in this order; prompts appear between entries):
6 7
1 2 4
1 3 1
3 2 1
2 4 5
3 4 8
4 5 3
5 6 2
1 6
Expected labeled result:
Minimum ambulance travel time: 12 minutes; Intersections on path: 1 3 2 4 5 6
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <EDGE weight, neighbor vertex>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start}); // <best tentative distance, vertex>
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first, node=p.second;
        if(distance!=dist[node]) continue; // outdated heap entry
        for(auto it:adj[node])
        {
            int weight=it.first, neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // MAIN CHANGE: remember previous vertex
                pq.push({dist[neighbor],neighbor});
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
        cout << "Enter road " << i+1 << " as: from to travel_minutes: ";
        cin >> u >> v >> w; // edge u-v has weight w; no vertex weights
        adj[u].push_back({w,v});
        adj[v].push_back({w,u}); // undirected/two-way
    }
    int A,B;
    cout << "Enter starting vertex and destination vertex: ";
    cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A);
    if(dist[B]==100000000)
    {
        cout << "Result: Destination is unreachable.\n";
        return 0;
    }
    cout << "Minimum ambulance travel time: " << dist[B] << " minutes\n";
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current); // destination to start
    reverse(path.begin(),path.end()); // now start to destination
    cout << "Intersections on path: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}
```

## 03_package_path.cpp

```cpp
/*
Package: warehouse to customer hub
Earlier code: Teacher Dijkstra -> earlier Tourist parent[] variation. Update dist and parent on relaxation.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 4 3
4 5 1
1 5
Expected labeled result:
Minimum shipping cost: 7; Hubs on path: 1 2 3 4 5
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <EDGE weight, neighbor vertex>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start}); // <best tentative distance, vertex>
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first, node=p.second;
        if(distance!=dist[node]) continue; // outdated heap entry
        for(auto it:adj[node])
        {
            int weight=it.first, neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // MAIN CHANGE: remember previous vertex
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of hubs (vertices) and routes (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter route " << i+1 << " as: from to shipping_cost: ";
        cin >> u >> v >> w; // edge u-v has weight w; no vertex weights
        adj[u].push_back({w,v});
        adj[v].push_back({w,u}); // undirected/two-way
    }
    int A,B;
    cout << "Enter starting vertex and destination vertex: ";
    cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A);
    if(dist[B]==100000000)
    {
        cout << "Result: Destination is unreachable.\n";
        return 0;
    }
    cout << "Minimum shipping cost: " << dist[B] << "\n";
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current); // destination to start
    reverse(path.begin(),path.end()); // now start to destination
    cout << "Hubs on path: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}
```

## 04_wildfire_nearest_shelter.cpp

```cpp
/*
Wildfire: fastest reachable shelter
Earlier code: Teacher Dijkstra -> parent[] variation -> compare K candidate distances and reconstruct chosen path.
Input example (type the numbers in this order; prompts appear between entries):
6 7
1 2 4
1 3 1
3 2 1
2 4 5
3 4 8
4 5 3
5 6 2
1 2
4 6
Expected labeled result:
Minimum evacuation time: 7 minutes; Chosen shelter vertex: 4; Vertices on chosen route: 1 3 2 4
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <edge travel time/cost, neighbor>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first,node=p.second;
        if(distance!=dist[node]) continue;
        for(auto it:adj[node])
        {
            int weight=it.first,neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // remember path
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of towns (vertices) and roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: from to travel_minutes: ";
        cin >> u >> v >> w; // edge weight; no vertex weight
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int A,K;
    cout << "Enter starting vertex A and number of shelters K: ";
    cin >> A >> K;
    vector<int> candidates(K);
    for(int i=0;i<K;i++)
    {
        cout << "Enter shelter vertex " << i+1 << ": ";
        cin >> candidates[i]; // VERTEX ID, not an edge weight
    }
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A); // one run gives shortest costs to ALL candidates

    int chosen=-1,best=100000000;
    for(int vertex:candidates)
        if(dist[vertex]<best) // MAIN CHANGE: choose nearest candidate
        {
            best=dist[vertex];
            chosen=vertex;
        }
    if(chosen==-1)
    {
        cout << "Result: No candidate is reachable.\n";
        return 0;
    }
    cout << "Minimum evacuation time: " << best << " minutes\n";
    cout << "Chosen shelter vertex: " << chosen << "\n";
    vector<int> path;
    for(int current=chosen;current!=-1;current=parent[current])
        path.push_back(current);
    reverse(path.begin(),path.end());
    cout << "Vertices on chosen route: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}
```

## 05_farm_nearest_cold_storage.cpp

```cpp
/*
Farm: cheapest reachable cold storage
Earlier code: Teacher Dijkstra -> parent[] variation -> compare K candidate distances and reconstruct chosen path.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 4 3
4 5 1
1 2
4 5
Expected labeled result:
Minimum shipping cost: 6; Chosen cold-storage vertex: 4; Vertices on chosen route: 1 2 3 4
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,dist[1000],parent[1000];
vector<pair<int,int>> adj[1000]; // <edge travel time/cost, neighbor>

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first,node=p.second;
        if(distance!=dist[node]) continue;
        for(auto it:adj[node])
        {
            int weight=it.first,neighbor=it.second;
            if(dist[neighbor]>distance+weight)
            {
                dist[neighbor]=distance+weight;
                parent[neighbor]=node; // remember path
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main()
{
    cout << "Enter number of hubs (vertices) and routes (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter route " << i+1 << " as: from to shipping_cost: ";
        cin >> u >> v >> w; // edge weight; no vertex weight
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int A,K;
    cout << "Enter starting vertex A and number of cold-storage facilities K: ";
    cin >> A >> K;
    vector<int> candidates(K);
    for(int i=0;i<K;i++)
    {
        cout << "Enter cold-storage facility vertex " << i+1 << ": ";
        cin >> candidates[i]; // VERTEX ID, not an edge weight
    }
    for(int i=1;i<=n;i++) { dist[i]=100000000; parent[i]=-1; }
    dijkstra(A); // one run gives shortest costs to ALL candidates

    int chosen=-1,best=100000000;
    for(int vertex:candidates)
        if(dist[vertex]<best) // MAIN CHANGE: choose nearest candidate
        {
            best=dist[vertex];
            chosen=vertex;
        }
    if(chosen==-1)
    {
        cout << "Result: No candidate is reachable.\n";
        return 0;
    }
    cout << "Minimum shipping cost: " << best << "\n";
    cout << "Chosen cold-storage vertex: " << chosen << "\n";
    vector<int> path;
    for(int current=chosen;current!=-1;current=parent[current])
        path.push_back(current);
    reverse(path.begin(),path.end());
    cout << "Vertices on chosen route: ";
    for(int vertex:path) cout << vertex << " ";
    cout << endl;
}
```

## NEW_01_change_directed_source_target.cpp

```cpp
/*
NEW EXAM VARIATION: Directed roads and arbitrary source/destination
Change from teacher's code: Keep only adj[u].push_back; read A,B; output dist[B].
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 2
2 4 3
1 3 10
3 4 1
4 1 7
1 4
Expected labeled output: Minimum directed travel cost from 1 to 4: 5
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int distance=p.first,node=p.second;
        if(distance!=dist[node]) continue;
        for(auto it:adj[node])
        {
            int w=it.first,neighbor=it.second;
            if(dist[neighbor]>distance+w)
            {
                dist[neighbor]=distance+w;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed edge " << i+1 << " as: from to weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); // MAIN CHANGE: no reverse v->u edge
    }
    int A,B;
    cout << "Enter source and destination vertices: "; cin >> A >> B;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000)
        cout << "Result: Destination unreachable.\n";
    else
        cout << "Minimum directed travel cost from " << A << " to "
             << B << ": " << dist[B] << "\n";
}
```

## NEW_02_change_blocked_vertices.cpp

```cpp
/*
NEW EXAM VARIATION: Shortest route while some vertices are closed
Change from teacher's code: Read K blocked vertices; never enter or expand them.
Input example (enter the numbers in order, without this explanatory text):
4 4 1
1 2 1
2 4 1
1 3 5
3 4 1
2
1 4
Expected labeled output: Minimum cost avoiding blocked vertices: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,dist[1000];
bool blocked[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0; pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,node=p.second;
        if(d!=dist[node] || blocked[node]) continue;
        for(auto it:adj[node])
        {
            int w=it.first,v=it.second;
            if(blocked[v]) continue; // MAIN CHANGE: do not enter closed vertex
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices, undirected edges, and number of blocked vertices: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    for(int i=0;i<k;i++)
    {
        int x;
        cout << "Enter blocked vertex " << i+1 << ": "; cin >> x;
        blocked[x]=true;
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    if(blocked[A] || blocked[B])
    { cout << "Result: Source or destination is blocked.\n"; return 0; }
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: No permitted route.\n";
    else cout << "Minimum cost avoiding blocked vertices: " << dist[B] << "\n";
}
```

## NEW_03_change_multiple_sources.cpp

```cpp
/*
NEW EXAM VARIATION: Nearest of several starting stations
Change from teacher's code: Push all K sources with distance 0; report nearest source and cost to B.
Input example (enter the numbers in order, without this explanatory text):
5 5
1 3 4
2 3 1
3 5 2
1 4 2
4 5 5
2
1 2
5
Expected labeled output: Nearest source vertex: 2; Minimum cost to destination 5: 3
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000],origin[1000];
vector<pair<int,int>> adj[1000]; // <edge weight, neighbor>
void multi_source_dijkstra(const vector<int>& sources)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    for(int s:sources) // MAIN CHANGE: all sources start at cost zero
    { dist[s]=0; origin[s]=s; pq.push({0,s}); }
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w)
            { dist[v]=d+w; origin[v]=origin[u]; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int K;
    cout << "Enter number of starting stations: "; cin >> K;
    vector<int> sources(K);
    for(int i=0;i<K;i++)
    { cout << "Enter source vertex " << i+1 << ": "; cin >> sources[i]; }
    int B;
    cout << "Enter destination vertex: "; cin >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; origin[i]=-1; }
    multi_source_dijkstra(sources);
    if(dist[B]==100000000) cout << "Result: Destination unreachable.\n";
    else
    {
        cout << "Nearest source vertex: " << origin[B] << "\n";
        cout << "Minimum cost to destination " << B << ": " << dist[B] << "\n";
    }
}
```

## NEW_04_change_count_shortest_paths.cpp

```cpp
/*
NEW EXAM VARIATION: Count how many shortest routes exist
Change from teacher's code: Maintain ways[v]; replace on a shorter distance and add on an equal distance.
Input example (enter the numbers in order, without this explanatory text):
4 4
1 2 1
1 3 1
2 4 1
3 4 1
1 4
Expected labeled output: Minimum cost: 2; Number of shortest routes: 2
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MOD=1000000007;
int n,m,dist[1000],ways[1000];
vector<pair<int,int>> adj[1000]; // positive edge weights required here
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[start]=0; ways[start]=1; pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w)
            {
                dist[v]=d+w;
                ways[v]=ways[u]; // new shorter distance: replace old count
                pq.push({dist[v],v});
            }
            else if(dist[v]==d+w)
                ways[v]=(ways[v]+ways[u])%MOD; // equal distance: add routes
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected positive-weight edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 positive_weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    for(int i=1;i<=n;i++) { dist[i]=100000000; ways[i]=0; }
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: No route.\n";
    else
    {
        cout << "Minimum cost: " << dist[B] << "\n";
        cout << "Number of shortest routes: " << ways[B] << "\n";
    }
}
```

## MORE_01_change_required_checkpoint.cpp

```cpp
/*
MORE EXAM VARIATION: Shortest route required to pass through checkpoint V
Change from teacher's code: Run Dijkstra from A and from V; answer dist_A[V]+dist_V[B].
Input example (numbers only, entered in this order):
4 4
1 2 2
2 3 2
3 4 2
1 4 3
1 3 4
Expected labeled output: Minimum cost via required checkpoint 3: 6
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector<pair<int,int>> adj[1000]; // <edge cost, neighbor>
vector<int> dijkstra(int source)
{
    vector<int> dist(n+1,100000000);
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[source]=0; pq.push({0,source});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
    return dist;
}
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A,V,B;
    cout << "Enter start, required checkpoint, and destination: ";
    cin >> A >> V >> B;
    vector<int> fromA=dijkstra(A),fromV=dijkstra(V); // MAIN CHANGE: two runs
    if(fromA[V]==100000000 || fromV[B]==100000000)
        cout << "Result: No route through the checkpoint.\n";
    else
        cout << "Minimum cost via required checkpoint " << V << ": "
             << fromA[V]+fromV[B] << "\n";
}
```

## MORE_02_change_forbidden_edge.cpp

```cpp
/*
MORE EXAM VARIATION: Shortest route avoiding one closed road
Change from teacher's code: Skip both directions of one specified undirected edge during relaxation.
Input example (numbers only, entered in this order):
4 4
1 2 1
2 4 1
1 3 3
3 4 1
2 4
1 4
Expected labeled output: Minimum cost avoiding closed road: 4
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000],X,Y;
vector<pair<int,int>> adj[1000];
void dijkstra(int A)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[A]=0; pq.push({0,A});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            // MAIN CHANGE: road X-Y is closed in BOTH directions.
            if((u==X && v==Y) || (u==Y && v==X)) continue;
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices and undirected weighted roads: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: vertex_1 vertex_2 time: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    cout << "Enter endpoints of the closed road: "; cin >> X >> Y;
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    if(dist[B]==100000000) cout << "Result: Destination unreachable.\n";
    else cout << "Minimum cost avoiding closed road: " << dist[B] << "\n";
}
```

## MORE_03_change_farthest_reachable_vertex.cpp

```cpp
/*
MORE EXAM VARIATION: Find farthest reachable vertex by shortest-path distance
Change from teacher's code: Run Dijkstra to all vertices, then scan dist[] for maximum finite distance.
Input example (numbers only, entered in this order):
4 3
1 2 2
2 3 3
1 4 4
1
Expected labeled output: Farthest reachable vertex: 3; Its shortest-path distance: 5
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[1000];
vector<pair<int,int>> adj[1000]; // <nonnegative edge weight,neighbor>
void dijkstra(int A)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    dist[A]=0; pq.push({0,A});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int d=p.first,u=p.second;
        if(d!=dist[u]) continue;
        for(auto it:adj[u])
        {
            int w=it.first,v=it.second;
            if(dist[v]>d+w) { dist[v]=d+w; pq.push({dist[v],v}); }
        }
    }
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int A; cout << "Enter source vertex: "; cin >> A;
    for(int i=1;i<=n;i++) dist[i]=100000000;
    dijkstra(A);
    int farthest=A;
    for(int i=1;i<=n;i++)
        if(dist[i]!=100000000 && dist[i]>dist[farthest])
            farthest=i; // MAIN CHANGE: maximum among finite shortest distances
    cout << "Farthest reachable vertex: " << farthest << "\n";
    cout << "Its shortest-path distance: " << dist[farthest] << "\n";
}
```

# Bellman_Ford: 7 standalone variations

## 01_banking_transaction_cost.cpp

```cpp
/*
Banking transfer/rebate network
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum transaction cost from source 1 to vertices 1..4: 0, 4, 2, 5
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
    cout << "Enter number of organizations (vertices) and directed transfers (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed transfer " << i+1 << " as: from to net_cost: ";
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
                cout << "Minimum transaction cost from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}
```

## 02_ev_battery_usage.cpp

```cpp
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
```

## 03_game_resource_cost.cpp

```cpp
/*
Game milestone spending minus rewards
Earlier code: Teacher Bellman-Ford. Completed the truncated main and added INF guard to relax().
Input example (type the numbers in this order; prompts appear between entries):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1
Expected labeled result:
Minimum resource cost from source 1 to vertices 1..4: 0, 4, 2, 5
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
    cout << "Enter number of milestones (vertices) and directed progression links (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter directed link " << i+1 << " as: from to spending_minus_reward: ";
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
                cout << "Minimum resource cost from vertex " << source
                     << " to vertex " << i << ": " << dist[i] << "\n";
        }
}
```

## NEW_01_change_negative_cycle_anywhere.cpp

```cpp
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
```

## NEW_02_change_path_reconstruction.cpp

```cpp
/*
NEW EXAM VARIATION: Shortest distance and route with negative edges
Change from teacher's code: Update parent[v] during relaxation and reverse the destination-to-source route.
Input example (enter the numbers in order, without this explanatory text):
4 4
1 2 4
1 3 5
2 3 -2
3 4 3
1 4
Expected labeled output: Minimum cost: 5; Shortest path: 1 2 3 4
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,dist[1000],parent[1000];
const int INF=100000000;
vector<pair<int,pair<int,int>>> edges; // <weight,<from,to>>
bool bellman_ford(int source)
{
    for(int i=1;i<=n;i++) { dist[i]=INF; parent[i]=-1; }
    dist[source]=0;
    for(int round=1;round<n;round++)
        for(auto edge:edges)
        {
            int w=edge.first,u=edge.second.first,v=edge.second.second;
            if(dist[u]!=INF && dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u; // MAIN CHANGE: save previous vertex
            }
        }
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(dist[u]!=INF && dist[v]>dist[u]+w) return false;
    }
    return true; // no negative cycle reachable from source
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
    int A,B;
    cout << "Enter source and destination vertices: "; cin >> A >> B;
    if(!bellman_ford(A))
    { cout << "Result: Reachable negative cycle; shortest route undefined.\n"; return 0; }
    if(dist[B]==INF)
    { cout << "Result: Destination unreachable.\n"; return 0; }
    vector<int> path;
    for(int current=B;current!=-1;current=parent[current])
        path.push_back(current);
    reverse(path.begin(),path.end());
    cout << "Minimum cost: " << dist[B] << "\n";
    cout << "Shortest path: ";
    for(int vertex:path) cout << vertex << " ";
    cout << "\n";
}
```

## MORE_01_change_at_most_k_edges.cpp

```cpp
/*
MORE EXAM VARIATION: Cheapest route using at most K edges
Change from teacher's code: Relax for K rounds using a previous-round copy so one round adds one edge.
Input example (numbers only, entered in this order):
3 3
1 2 2
2 3 -5
1 3 1
1 3 2
Expected labeled output: Minimum cost using at most 2 edges: -3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
using namespace std;
struct Edge { int u,v,w; };
int n,m;
vector<Edge> edges;
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    int A,B,K;
    cout << "Enter source, destination, and maximum edge count K: ";
    cin >> A >> B >> K;
    const int INF=100000000;
    vector<int> previous(n+1,INF);
    previous[A]=0;
    for(int round=1;round<=K;round++)
    {
        vector<int> current=previous; // keep solutions using fewer edges
        for(Edge e:edges)
            if(previous[e.u]!=INF && current[e.v]>previous[e.u]+e.w)
                current[e.v]=previous[e.u]+e.w;
        // MAIN CHANGE: use previous, not current, for each relaxation round.
        previous=current;
    }
    if(previous[B]==INF) cout << "Result: No route within edge limit.\n";
    else cout << "Minimum cost using at most " << K
              << " edges: " << previous[B] << "\n";
}
```

## MORE_02_change_cycle_affects_destination.cpp

```cpp
/*
MORE EXAM VARIATION: Determine whether a negative cycle makes target cost unbounded
Change from teacher's code: After n-1 rounds, propagate improvable vertices through outgoing edges.
Input example (numbers only, entered in this order):
5 5
1 2 1
2 3 -2
3 2 1
3 4 2
1 5 5
1 4
Expected labeled output: Negative cycle can affect destination 4: YES
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge { int u,v,w; };
int n,m,dist[1000];
bool affected[1000];
vector<Edge> edges;
vector<int> adj[1000];
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
        adj[e.u].push_back(e.v); // direction matters
    }
    int A,B;
    cout << "Enter source and destination: "; cin >> A >> B;
    const int INF=100000000;
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[A]=0;
    for(int round=1;round<n;round++)
        for(Edge e:edges)
            if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w)
                dist[e.v]=dist[e.u]+e.w;
    queue<int> q;
    for(Edge e:edges)
        if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w && !affected[e.v])
        { affected[e.v]=true; q.push(e.v); }
    // MAIN CHANGE: any vertex reachable from an improvable vertex is affected.
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
            if(!affected[v]) { affected[v]=true; q.push(v); }
    }
    cout << "Negative cycle can affect destination " << B << ": "
         << (affected[B] ? "YES" : "NO") << "\n";
    if(!affected[B] && dist[B]==INF)
        cout << "Destination is unreachable from source.\n";
    else if(!affected[B])
        cout << "Finite minimum cost to destination: " << dist[B] << "\n";
}
```

# DSU: 5 standalone variations

## 01_corporate_merge_query.cpp

```cpp
/*
Corporate MERGE / QUERY operations
Earlier code: Teacher Kruskal DSU functions; remove edge sorting and MST cost.
Input example (type the numbers in this order; prompts appear between entries):
5 6
MERGE 1 2
QUERY 1 3
MERGE 2 3
QUERY 1 3
QUERY 4 5
MERGE 4 5
Expected labeled result:
Query 1,3: NO; Query 1,3: YES; Query 4,5: NO
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<string>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // teacher's find (no path compression)
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter number of companies and operations: ";
    cin >> n >> m; // m is operation count, not edge count
    initialize();
    for(int i=0;i<m;i++)
    {
        string operation; int A,B;
        cout << "Enter operation " << i+1 << " as MERGE A B or QUERY A B: ";
        cin >> operation >> A >> B;
        if(operation=="MERGE")
        {
            union_sets(A,B); // merge groups; no weights
            cout << "Merge completed for companies " << A << " and " << B << ".\n";
        }
        else if(operation=="QUERY")
        {
            cout << "Connection result for companies " << A << " and " << B
                 << ": " << (find(A)==find(B) ? "YES" : "NO") << "\n";
        }
    }
}
```

## NEW_01_change_component_count_and_size.cpp

```cpp
/*
NEW EXAM VARIATION: Report number of groups and size of a queried group
Change from teacher's code: Store size at each root; decrease component count after a successful union.
Input example (enter the numbers in order, without this explanatory text):
5 3
1 2
2 3
4 5
2
Expected labeled output: Number of connected groups: 2; Size of group containing 2: 3
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000],group_size[1000],components;
void initialize()
{
    components=n;
    for(int i=1;i<=n;i++)
    { _parent[i]=i; _rank[i]=0; group_size[i]=1; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]);
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]<_rank[rooty]) swap(rootx,rooty);
    _parent[rooty]=rootx;
    group_size[rootx]+=group_size[rooty]; // MAIN CHANGE: combine sizes
    if(_rank[rootx]==_rank[rooty]) _rank[rootx]++;
    components--; // two groups become one
    return true;
}
int main()
{
    cout << "Enter number of vertices and connections: "; cin >> n >> m;
    initialize();
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "Enter connection " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v); // no edge/vertex weights
    }
    int x;
    cout << "Enter vertex whose group size you want: "; cin >> x;
    cout << "Number of connected groups: " << components << "\n";
    cout << "Size of group containing " << x << ": "
         << group_size[find(x)] << "\n";
}
```

## NEW_02_change_detect_undirected_cycle.cpp

```cpp
/*
NEW EXAM VARIATION: Check whether an undirected graph has a cycle
Change from teacher's code: If union_sets(u,v) returns false, this edge closes a cycle.
Input example (enter the numbers in order, without this explanatory text):
3 3
1 2
2 3
1 3
Expected labeled output: Cycle detected in undirected graph: YES
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
using namespace std;
int n,m,_parent[1000],_rank[1000];
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter vertices and undirected edges: "; cin >> n >> m;
    initialize();
    bool cycle=false;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        if(!union_sets(u,v)) cycle=true; // MAIN CHANGE: same-root edge creates cycle
    }
    cout << "Cycle detected in undirected graph: "
         << (cycle ? "YES" : "NO") << "\n";
}
```

## MORE_01_change_first_step_all_connected.cpp

```cpp
/*
MORE EXAM VARIATION: Earliest operation when every vertex becomes connected
Change from teacher's code: Track component count after each union and stop at one.
Input example (numbers only, entered in this order):
4 4
1 2
3 4
2 3
1 4
Expected labeled output: First operation connecting all vertices: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
using namespace std;
int n,m,_parent[1000],_rank[1000],components;
void initialize()
{ components=n; for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    components--; // MAIN CHANGE: count groups after each event
    return true;
}
int main()
{
    cout << "Enter vertices and chronological connection events: "; cin >> n >> m;
    initialize();
    int first=(n==1 ? 0 : -1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cout << "Enter connection event " << i << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v);
        if(components==1 && first==-1) first=i;
    }
    if(first==-1) cout << "Result: Never fully connected.\n";
    else cout << "First operation connecting all vertices: " << first << "\n";
}
```

## MORE_02_change_dynamic_size_and_count_queries.cpp

```cpp
/*
MORE EXAM VARIATION: Dynamic MERGE, SIZE, and COUNT commands
Change from teacher's code: Store component sizes and count while processing mixed operations.
Input example (numbers only, entered in this order):
4 5
MERGE 1 2
SIZE 2
COUNT
MERGE 2 3
SIZE 3
Expected labeled output: Size of group containing 2: 2; Number of groups: 3; Size of group containing 3: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000],group_size[1000],components;
void initialize()
{
    components=n;
    for(int i=1;i<=n;i++)
    { _parent[i]=i; _rank[i]=0; group_size[i]=1; }
}
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
void union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return;
    if(_rank[a]<_rank[b]) swap(a,b);
    _parent[b]=a;
    group_size[a]+=group_size[b];
    if(_rank[a]==_rank[b]) _rank[a]++;
    components--;
}
int main()
{
    cout << "Enter vertices and number of operations: "; cin >> n >> m;
    initialize();
    for(int i=0;i<m;i++)
    {
        string op;
        cout << "Enter operation " << i+1 << " (MERGE A B, SIZE A, or COUNT): ";
        cin >> op;
        if(op=="MERGE")
        {
            int A,B; cin >> A >> B; // two vertex IDs
            union_sets(A,B);
            cout << "Merged groups of " << A << " and " << B << ".\n";
        }
        else if(op=="SIZE")
        {
            int A; cin >> A;
            cout << "Size of group containing " << A << ": "
                 << group_size[find(A)] << "\n";
        }
        else if(op=="COUNT")
            cout << "Number of groups: " << components << "\n";
    }
}
```

# Kruskal: 12 standalone variations

## 01_min_tree_largest_edge.cpp

```cpp
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
```

## 02_max_tree_weakest_edge.cpp

```cpp
/*
Weakest edge in a Maximum Spanning Tree
Earlier code: Earlier Question 7; same as CT-2-A Problem 2.
Input example (type the numbers in this order; prompts appear between entries):
5 6
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
Expected labeled result:
Weakest link in the maximum-bandwidth backbone: 5 Gbps
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
    cout << "Enter number of data centers (vertices) and possible links (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter link " << i+1 << " as: vertex_1 vertex_2 bandwidth_Gbps: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // maximum tree: descending
    int answer=INT_MAX,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=min(answer,w); // weakest SELECTED edge
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Weakest link in the maximum-bandwidth backbone: " << answer << " Gbps\n";
}
```

## 03_max_truck_weight.cpp

```cpp
/*
Disaster Relief: maximum safe truck weight
Earlier code: Earlier Question 7; descending sort, minimum selected limit.
Input example (type the numbers in this order; prompts appear between entries):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled result:
Maximum truck weight that can reach every city: 6
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
    cout << "Enter number of cities (vertices) and roads (edges): ";
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter road " << i+1 << " as: vertex_1 vertex_2 maximum_truck_weight: ";
        cin >> u >> v >> w; // no vertex weights
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // strongest road first
    int answer=INT_MAX,taken=0;
    for(auto edge:edges)
    {
        int w=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v))
        {
            answer=min(answer,w); // weakest road limits the truck
            taken++;
        }
    }
    if(n==1) cout << "Result: No selected edge for one vertex.\n";
    else if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum truck weight that can reach every city: " << answer << "\n";
}
```

## 04_fiber_existing_required.cpp

```cpp
/*
Minimum-cost fiber network with existing links and required cable
Earlier code: Teacher Kruskal: union existing links before sorting; pay for and union required edge.
Input example (type the numbers in this order; prompts appear between entries):
4 4 1
1 3 8
2 3 4
2 4 9
1 4 20
1 2
3 4 6
Expected labeled result:
Minimum total cable construction cost: 10
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
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

int k;
vector<pair<int,pair<int,int>>> edges; // <cost,<u,v>>
int main()
{
    cout << "Enter number of islands, optional cables, and existing connections: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1
             << " as: island_1 island_2 construction_cost: ";
        cin >> u >> v >> cost; // edge weight is cost
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v); // cost zero, already connected
    }
    int X,Y,required_cost;
    cout << "Enter required cable as: island_1 island_2 construction_cost: ";
    cin >> X >> Y >> required_cost;
    int total_cost=required_cost; // pay EVEN if endpoints already connected
    union_sets(X,Y);
    sort(edges.begin(),edges.end()); // cheaper optional edges first
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(union_sets(u,v)) total_cost+=cost;
    }
    int root=find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=root)
        {
            cout << "Result: Cannot connect all islands.\n";
            return 0;
        }
    cout << "Minimum total cable construction cost: " << total_cost << "\n";
}
```

## 05_budget_tower_count.cpp

```cpp
/*
Budgeted cable construction: one tower per remaining component
Earlier code: Teacher Kruskal: budget check before union, then count DSU roots.
Input example (type the numbers in this order; prompts appear between entries):
5 5 1 6
1 2 2
2 3 3
3 4 4
4 5 5
1 5 10
1 2
Expected labeled result:
Cable construction cost used: 3; Number of towers needed: 3
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<vector>
#include<algorithm>
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

int k,B;
vector<pair<int,pair<int,int>>> edges; // <construction cost,<u,v>>
int main()
{
    cout << "Enter islands, optional cables, existing connections, and budget: ";
    cin >> n >> m >> k >> B; // B is a budget, not a vertex weight
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter optional cable " << i+1 << " as: island_1 island_2 cost: ";
        cin >> u >> v >> cost;
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter existing free connection " << i+1 << " as: island_1 island_2: ";
        cin >> u >> v;
        union_sets(u,v);
    }
    sort(edges.begin(),edges.end()); // cheapest useful edges first
    int total_cost=0;
    for(auto edge:edges)
    {
        int cost=edge.first,u=edge.second.first,v=edge.second.second;
        if(find(u)==find(v)) continue; // already same component
        if(total_cost+cost<=B) // check BEFORE spending
        {
            union_sets(u,v);
            total_cost+=cost;
        }
        else break; // sorted nonnegative costs; later edges cost at least as much
    }
    int towers=0;
    for(int i=1;i<=n;i++)
        if(find(i)==i) towers++; // one tower for each DSU component
    cout << "Cable construction cost used: " << total_cost << "\n";
    cout << "Number of towers needed: " << towers << "\n";
}
```

## 06_metro_prebuilt_max_bandwidth.cpp

```cpp
/*
Metro fiber: prebuilt 0-based indexed routes
Earlier code: Teacher Kruskal + prebuilt DSU unions; sort descending, include forced bandwidth in sum.
Input example (type the numbers in this order; prompts appear between entries):
5 6 1
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
4
Expected labeled result:
Total bandwidth of the selected backbone: 25 Gbps
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

struct Edge { int u,v,w; };
vector<Edge> original_edges,optional_edges;
bool forced[1000];
bool larger_weight(Edge a,Edge b) { return a.w>b.w; }

int main()
{
    int k;
    cout << "Enter number of hubs, candidate fiber, and already-built routes: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter route index " << i << " as: vertex_1 vertex_2 bandwidth_Gbps: ";
        cin >> e.u >> e.v >> e.w;
        original_edges.push_back(e); // preserve 0-based input indexes
    }
    initialize();
    int selected=0;
    int answer=0;
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter 0-based index of already-built route " << i+1 << ": ";
        cin >> index; // INDEX of an edge, NOT a vertex ID
        if(index<0 || index>=m || forced[index])
        {
            cout << "Result: Invalid or repeated route index.\n";
            return 0;
        }
        forced[index]=true;
        Edge e=original_edges[index];
        if(!union_sets(e.u,e.v))
        {
            cout << "Result: Forced routes create a cycle; no spanning tree exists.\n";
            return 0;
        }
        answer=answer+e.w; // forced edge's bandwidth/capacity MUST count
        selected++;
    }
    for(int i=0;i<m;i++)
        if(!forced[i]) optional_edges.push_back(original_edges[i]);
    sort(optional_edges.begin(),optional_edges.end(),larger_weight);
    for(Edge e:optional_edges)
        if(union_sets(e.u,e.v))
        {
            answer=answer+e.w; // add only edges joining components
            selected++;
        }
    if(selected!=n-1)
        cout << "Result: Cannot connect all vertices into a spanning tree.\n";
    else
        cout << "Total bandwidth of the selected backbone: " << answer << " Gbps\n";
}
```

## 07_rail_mandatory_weakest.cpp

```cpp
/*
Rail corridors: mandatory 0-based indexed routes
Earlier code: Teacher max Kruskal, force indexed edges before sort, min over ALL selected capacities.
Input example (type the numbers in this order; prompts appear between entries):
5 6 1
1 2 3
1 3 8
2 3 5
2 4 6
3 5 2
4 5 9
0
Expected labeled result:
Weakest capacity among selected corridors: 3
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

struct Edge { int u,v,w; };
vector<Edge> original_edges,optional_edges;
bool forced[1000];
bool larger_weight(Edge a,Edge b) { return a.w>b.w; }

int main()
{
    int k;
    cout << "Enter number of towns, candidate rail, and mandatory routes: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter route index " << i << " as: vertex_1 vertex_2 passenger_capacity: ";
        cin >> e.u >> e.v >> e.w;
        original_edges.push_back(e); // preserve 0-based input indexes
    }
    initialize();
    int selected=0;
    int answer=INT_MAX;
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter 0-based index of mandatory route " << i+1 << ": ";
        cin >> index; // INDEX of an edge, NOT a vertex ID
        if(index<0 || index>=m || forced[index])
        {
            cout << "Result: Invalid or repeated route index.\n";
            return 0;
        }
        forced[index]=true;
        Edge e=original_edges[index];
        if(!union_sets(e.u,e.v))
        {
            cout << "Result: Forced routes create a cycle; no spanning tree exists.\n";
            return 0;
        }
        answer=min(answer,e.w); // forced edge's bandwidth/capacity MUST count
        selected++;
    }
    for(int i=0;i<m;i++)
        if(!forced[i]) optional_edges.push_back(original_edges[i]);
    sort(optional_edges.begin(),optional_edges.end(),larger_weight);
    for(Edge e:optional_edges)
        if(union_sets(e.u,e.v))
        {
            answer=min(answer,e.w); // add only edges joining components
            selected++;
        }
    if(selected!=n-1)
        cout << "Result: Cannot connect all vertices into a spanning tree.\n";
    else
        cout << "Weakest capacity among selected corridors: " << answer << "\n";
}
```

## NEW_01_change_maximum_total_weight.cpp

```cpp
/*
NEW EXAM VARIATION: Maximum Spanning Tree total weight
Change from teacher's code: Sort descending and SUM selected edge weights (rather than taking min edge).
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled output: Maximum spanning tree total weight: 21
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges; // <weight,<u,v>>
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    initialize();
    sort(edges.rbegin(),edges.rend()); // MAIN CHANGE: largest edge first
    int total=0,taken=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
        { total+=edge.first; taken++; } // sum, not weakest edge
    if(taken!=n-1) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum spanning tree total weight: " << total << "\n";
}
```

## NEW_02_change_existing_free_links_no_mandatory.cpp

```cpp
/*
NEW EXAM VARIATION: Minimum additional cost with existing free links
Change from teacher's code: Union K existing pairs first; then run ascending Kruskal, without a required cable.
Input example (enter the numbers in order, without this explanatory text):
4 4 1
1 3 8
2 3 4
2 4 9
3 4 6
1 2
Expected labeled output: Minimum additional construction cost: 10
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges; // <cost,<u,v>>
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter vertices, candidate edges, and existing free connections: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cout << "Enter candidate edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> cost;
        edges.push_back({cost,{u,v}});
    }
    initialize();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cout << "Enter free existing connection " << i+1 << " as: vertex_1 vertex_2: ";
        cin >> u >> v;
        union_sets(u,v); // MAIN CHANGE: free connectivity before Kruskal
    }
    sort(edges.begin(),edges.end());
    int total=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
            total+=edge.first;
    int root=find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=root)
        { cout << "Result: Cannot connect all vertices.\n"; return 0; }
    cout << "Minimum additional construction cost: " << total << "\n";
}
```

## NEW_03_change_stop_at_k_components.cpp

```cpp
/*
NEW EXAM VARIATION: Minimum-cost grouping into exactly K connected components
Change from teacher's code: Run ascending Kruskal and stop when component count reaches K.
Input example (enter the numbers in order, without this explanatory text):
5 5 2
1 2 1
2 3 2
3 4 3
4 5 4
1 5 10
Expected labeled output: Minimum cost to form 2 groups: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,K,_parent[1000],_rank[1000],components;
vector<pair<int,pair<int,int>>> edges;
void initialize()
{ components=n; for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    { _parent[rooty]=rootx; _rank[rootx]++; }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    components--; // count connected groups
    return true;
}
int main()
{
    cout << "Enter vertices, edges, and desired number of groups K: ";
    cin >> n >> m >> K;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    if(K<1 || K>n) { cout << "Result: Invalid K.\n"; return 0; }
    initialize();
    sort(edges.begin(),edges.end());
    int total=0;
    for(auto edge:edges)
    {
        if(components==K) break; // MAIN CHANGE: stop before full MST
        if(union_sets(edge.second.first,edge.second.second))
            total+=edge.first;
    }
    if(components!=K) cout << "Result: Cannot form exactly K groups.\n";
    else cout << "Minimum cost to form " << K << " groups: " << total << "\n";
}
```

## MORE_01_change_total_savings.cpp

```cpp
/*
MORE EXAM VARIATION: Savings after replacing all roads with an MST
Change from teacher's code: Sum all edge costs and subtract minimum spanning tree cost.
Input example (numbers only, entered in this order):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Total original cost: 15; Minimum network cost: 6; Savings: 9
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000];
vector<pair<int,pair<int,int>>> edges;
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    return true;
}
int main()
{
    cout << "Enter vertices and weighted edges: "; cin >> n >> m;
    int original_total=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
        original_total+=w; // cost of ALL input edges
    }
    initialize(); sort(edges.begin(),edges.end());
    int mst_cost=0,taken=0;
    for(auto edge:edges)
        if(union_sets(edge.second.first,edge.second.second))
        { mst_cost+=edge.first; taken++; }
    if(taken!=n-1) { cout << "Result: Full network impossible.\n"; return 0; }
    // MAIN CHANGE: compare original total with selected MST edges.
    cout << "Total original cost: " << original_total << "\n";
    cout << "Minimum network cost: " << mst_cost << "\n";
    cout << "Savings: " << original_total-mst_cost << "\n";
}
```

## MORE_02_change_forbidden_edge_indices.cpp

```cpp
/*
MORE EXAM VARIATION: MST with certain routes forbidden by 0-based index
Change from teacher's code: Exclude forbidden indexes before sorting optional edges.
Input example (numbers only, entered in this order):
4 5 1
1 2 1
2 3 2
3 4 3
1 4 10
1 3 4
1
Expected labeled output: Minimum spanning tree cost avoiding forbidden routes: 8
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,_parent[1000],_rank[1000];
bool forbidden[1000];
vector<pair<int,pair<int,int>>> original,allowed;
void initialize()
{ for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; } }
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
bool union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return false;
    if(_rank[a]==_rank[b]) { _parent[b]=a; _rank[a]++; }
    else if(_rank[a]>_rank[b]) _parent[b]=a;
    else _parent[a]=b;
    return true;
}
int main()
{
    cout << "Enter vertices, routes, and forbidden route count: ";
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter route at 0-based index " << i
             << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        original.push_back({w,{u,v}});
    }
    for(int i=0;i<k;i++)
    {
        int index;
        cout << "Enter forbidden 0-based route index " << i+1 << ": ";
        cin >> index; // edge index, not vertex ID
        if(index<0 || index>=m)
        { cout << "Result: Invalid route index.\n"; return 0; }
        forbidden[index]=true;
    }
    for(int i=0;i<m;i++)
        if(!forbidden[i]) allowed.push_back(original[i]); // MAIN CHANGE
    initialize(); sort(allowed.begin(),allowed.end());
    int total=0,taken=0;
    for(auto edge:allowed)
        if(union_sets(edge.second.first,edge.second.second))
        { total+=edge.first; taken++; }
    if(taken!=n-1) cout << "Result: No permitted spanning tree.\n";
    else cout << "Minimum spanning tree cost avoiding forbidden routes: "
              << total << "\n";
}
```

# Prims: 3 standalone variations

## NEW_01_change_maximum_spanning_total.cpp

```cpp
/*
NEW EXAM VARIATION: Prim with maximum heap for a Maximum Spanning Tree
Change from teacher's code: Use default max heap instead of min heap, and sum selected edge weights.
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 8
2 3 6
3 4 5
1 4 3
2 4 7
Expected labeled output: Maximum spanning tree total weight using Prim: 21
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <edge weight,neighbor>
bool prims_max(int start,int& total)
{
    priority_queue<pair<int,int>> pq; // MAIN CHANGE: max heap
    pq.push({0,start});
    total=0;
    int seen=0;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int weight=p.first,node=p.second;
        if(visited[node]) continue;
        visited[node]=true;
        total+=weight; // chosen edge, 0 for start
        seen++;
        for(auto it:adj[node])
            if(!visited[it.second]) pq.push(it);
    }
    return seen==n; // false means disconnected
}
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    int total;
    if(!prims_max(1,total)) cout << "Result: Cannot connect all vertices.\n";
    else cout << "Maximum spanning tree total weight using Prim: " << total << "\n";
}
```

## NEW_02_change_print_selected_mst_edges.cpp

```cpp
/*
NEW EXAM VARIATION: Prim prints selected Minimum Spanning Tree edges
Change from teacher's code: Store parent inside heap items and print the chosen edge on first visit.
Input example (enter the numbers in order, without this explanatory text):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Selected edges: 1-2 (1), 2-3 (2), 3-4 (3); Total MST cost: 6
Remove prompts and descriptive output labels for exact-output online judges.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <edge weight,neighbor>
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    // <weight,vertex,parent>. tuple min heap keeps lowest weight first.
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;
    pq.push({0,1,-1});
    int total=0,seen=0;
    cout << "Selected MST edges:\n";
    while(!pq.empty())
    {
        auto item=pq.top(); pq.pop();
        int w=get<0>(item),node=get<1>(item),parent=get<2>(item);
        if(visited[node]) continue;
        visited[node]=true; seen++; total+=w;
        // MAIN CHANGE: parent tells us WHICH edge was selected.
        if(parent!=-1)
            cout << "Edge " << parent << "-" << node << " has cost " << w << "\n";
        for(auto it:adj[node])
            if(!visited[it.second]) pq.push({it.first,it.second,node});
    }
    if(seen!=n) cout << "Result: Graph disconnected; full MST does not exist.\n";
    else cout << "Total MST cost: " << total << "\n";
}
```

## MORE_01_change_report_largest_mst_edge.cpp

```cpp
/*
MORE EXAM VARIATION: Prim finds largest selected edge in a minimum spanning tree
Change from teacher's code: During each first visit, update max_edge instead of only returning total cost.
Input example (numbers only, entered in this order):
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 3
Expected labeled output: Largest edge weight selected by Prim MST: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int n,m;
bool visited[1000];
vector<pair<int,int>> adj[1000]; // <cost,neighbor>
int main()
{
    cout << "Enter vertices and undirected weighted edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cout << "Enter edge " << i+1 << " as: vertex_1 vertex_2 cost: ";
        cin >> u >> v >> w;
        adj[u].push_back({w,v}); adj[v].push_back({w,u});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,
                   greater<pair<int,int>>> pq; // min heap
    pq.push({0,1});
    int seen=0,max_edge=INT_MIN;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top(); pq.pop();
        int w=p.first,u=p.second;
        if(visited[u]) continue;
        visited[u]=true; seen++;
        if(u!=1) max_edge=max(max_edge,w); // MAIN CHANGE: selected bottleneck
        for(auto it:adj[u])
            if(!visited[it.second]) pq.push(it);
    }
    if(seen!=n) cout << "Result: Cannot form a full MST.\n";
    else if(n==1) cout << "Result: No edge selected for one vertex.\n";
    else cout << "Largest edge weight selected by Prim MST: " << max_edge << "\n";
}
```

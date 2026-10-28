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

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

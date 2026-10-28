#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n; // node
int m; //edge


/// adj[x] means a list of pairs: <weight, neighbor>. adj[x]= [<1,y>, <3,z>......] [ y and z are neighbor of x]

bool visited[1000];
vector<pair<int,int>>adj[1000];

int prims(int start) /// a starting node
{
    /// need min heap

    //priority_queue<pair<int,int>> pq; /// max-heap
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap

    /// initially, keep the start node inside min-heap
    pq.push({0,start});
    int cost=0;
    while(!pq.empty()) // run till pq is empty
    {
        /// extract --> visit that node --> push neighbors (a loop)

        pair<int,int>p=pq.top(); /// extract
        pq.pop();
        int weight=p.first;
        int node=p.second;
        /// visit
        if(visited[node]==false)
        {
            visited[node]=true;
            cost+=weight; /// to visit, we need to add that edge

        }
        /// push neighbors
        for(auto it: adj[node]) /// visit the adjacency/neighbor list of that node
        {
            // "it" is a pair in the adjacency list of node. one by one, visit every pair using loop
            int weight=it.first;
            int neighbor=it.second;
            if(visited[neighbor]==false)
            {
                // push <WEIGHT, NEIGHBOR>
                pq.push({weight, neighbor});
            }

        }


    }
    return cost;

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int start, end, weight;
        cin>>start>>end>>weight;

        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});

    }

    cout<<prims(1)<<endl;

}
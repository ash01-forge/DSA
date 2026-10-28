/// QUESTION: Directed graph-e source to destination shortest path.
/// ALGORITHM: Dijkstra + Parent Array
/// CHANGE 1: parent[]=-1; shorter distance-e parent update.
/// CHANGE 2: Path parent follow kore reverse-e print.
/// CHANGE 3: Directed edge: reverse adjacency push nei.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const bool SHOW_PROMPTS=true; /// Practice: true; question-er exact output: false.

int n;
int m;
bool visited[1000];
/// pair<weight,neighbor>
vector<pair<int,int>>adj[1000];
int dist[1000];
int parent[1000];

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>>pq;

    pq.push({0,start});

    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int distance=p.first;
        int node=p.second;

        if(visited[node]==false)
        {
            visited[node]=true;
            dist[node]=distance;
        }

        for(auto it:adj[node])
        {
            int weight=it.first;
            int neighbor=it.second;
            int neighbour_distance=distance+weight;

            if(visited[neighbor]==false &&
               neighbour_distance<dist[neighbor])
            {
                /// CHANGE: shortest distance improve hole parent update.
                dist[neighbor]=neighbour_distance;
                parent[neighbor]=node;

                pq.push({neighbour_distance,neighbor});
            }
        }
    }
}

int main()
{
    if(SHOW_PROMPTS)
        cout<<"Enter n m:"<<endl;
    cin>>n>>m;

    if(SHOW_PROMPTS)
        cout<<"Enter m directed edges: start end travel_time"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
    }

    if(SHOW_PROMPTS)
        cout<<"Enter source A and destination B:"<<endl;
    int a,b;
    cin>>a>>b;

    for(int i=0;i<=n;i++)
    {
        dist[i]=100000000;
        parent[i]=-1;
    }

    dijkstra(a);

    if(SHOW_PROMPTS)
        cout<<"Minimum travel time: ";
    cout<<dist[b]<<endl;
    if(dist[b]==100000000)
    {
        cout<<"No path"<<endl;
    }
    else
    {
        /// CHANGE: destination theke parent follow kore reverse-e print.
        vector<int>path;
        int node=b;

        while(node!=-1)
        {
            path.push_back(node);
            node=parent[node];
        }

        if(SHOW_PROMPTS)
            cout<<"Path: ";
        for(int i=(int)path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;
    }
}

/*
CURRENT INPUT (uporer active main-er input):
n m
m line: start end weight
a b
Edges directed: shudhu start -> end.

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Minimum travel time
A-to-B path; unreachable hole distance 100000000, then No path

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format: n m a b; tarpor m weighted edges.
CHANGE: a,b first line-e declare/read; edge list-er pore a,b input bad.

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    if(SHOW_PROMPTS)
        cout<<"Enter n m a b:"<<endl;
    /// INPUT CHANGE 1: source/destination first line-e.
    int a,b;
    cin>>n>>m>>a>>b;

    if(SHOW_PROMPTS)
        cout<<"Enter m directed edges: start end travel_time"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
    }

    /// INPUT CHANGE 2: a,b age pora hoyeche; ekhane abar input nei.

    for(int i=0;i<=n;i++)
    {
        dist[i]=100000000;
        parent[i]=-1;
    }

    dijkstra(a);

    if(SHOW_PROMPTS)
        cout<<"Minimum travel time: ";
    cout<<dist[b]<<endl;
    if(dist[b]==100000000)
    {
        cout<<"No path"<<endl;
    }
    else
    {
        /// CHANGE: destination theke parent follow kore reverse-e print.
        vector<int>path;
        int node=b;

        while(node!=-1)
        {
            path.push_back(node);
            node=parent[node];
        }

        if(SHOW_PROMPTS)
            cout<<"Path: ";
        for(int i=(int)path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;
    }
}
--- ALTERNATIVE MAIN END ---
*/

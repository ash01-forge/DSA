/// QUESTION: Travel cost + entered node-er fee diye shortest total cost.
/// ALGORITHM: Dijkstra
/// CHANGE 1: entry_fee[neighbor] neighbour_distance-e jog.
/// CHANGE 2: Starting node-er fee jog hoy na.

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
int entry_fee[1000];

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

            /// CHANGE: destination node-er cost jog; source cost jog hoy na.
            int neighbour_distance=distance+weight+entry_fee[neighbor];

            if(visited[neighbor]==false)
            {
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
        cout<<"Enter m edges: start end travel_cost"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});
    }

    if(SHOW_PROMPTS)
        cout<<"Enter entry fees 1 to n:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>entry_fee[i];

    if(SHOW_PROMPTS)
        cout<<"Enter source and destination:"<<endl;
    int source,destination;
    cin>>source>>destination;

    for(int i=0;i<=n;i++)
    {
        dist[i]=100000000;
    }

    dijkstra(source);

    if(SHOW_PROMPTS)
        cout<<"Minimum total cost: ";
    cout<<dist[destination]<<endl;
}

/*
CURRENT INPUT (uporer active main-er input):
n m
m line: start end travel_cost
fee1 fee2 ... feen
source destination

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Minimum total cost

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format: n m source destination; m roads; n entry fees.
CHANGE: source,destination first line-e; fees-er pore abar input bad.

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    if(SHOW_PROMPTS)
        cout<<"Enter n m source destination:"<<endl;
    /// INPUT CHANGE 1: source/destination first line-e.
    int source,destination;
    cin>>n>>m>>source>>destination;

    if(SHOW_PROMPTS)
        cout<<"Enter m edges: start end travel_cost"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});
    }

    if(SHOW_PROMPTS)
        cout<<"Enter entry fees 1 to n:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>entry_fee[i];

    /// INPUT CHANGE 2: source/destination age pora hoyeche.

    for(int i=0;i<=n;i++)
    {
        dist[i]=100000000;
    }

    dijkstra(source);

    if(SHOW_PROMPTS)
        cout<<"Minimum total cost: ";
    cout<<dist[destination]<<endl;
}
--- ALTERNATIVE MAIN END ---
*/

/// QUESTION: Maximum total weight spanning tree.
/// ALGORITHM: Prim's Maximum Spanning Tree
/// CHANGE 1: Min-heap-er bodole max-heap; baki faculty structure eki.

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

int prims(int start)
{
    /// CHANGE: normal priority_queue holo max-heap.
    priority_queue<pair<int,int>>pq;

    pq.push({0,start});
    int cost=0;

    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int weight=p.first;
        int node=p.second;

        if(visited[node]==false)
        {
            visited[node]=true;
            cost+=weight;
        }

        for(auto it:adj[node])
        {
            int weight=it.first;
            int neighbor=it.second;

            if(visited[neighbor]==false)
                pq.push({weight,neighbor});
        }
    }

    return cost;
}

int main()
{
    if(SHOW_PROMPTS)
        cout<<"Enter n m:"<<endl;
    cin>>n>>m;

    if(SHOW_PROMPTS)
        cout<<"Enter m edges: start end weight"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});
    }

    if(SHOW_PROMPTS)
        cout<<"Maximum spanning tree weight: ";
    cout<<prims(1)<<endl;
}

/*
CURRENT INPUT (uporer active main-er input):
n m
m line: start end weight

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Maximum spanning tree total weight

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format: n m; m weighted edges; starting_node.
CHANGE: main-er sheshe start input; prims(1) -> prims(start).

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    if(SHOW_PROMPTS)
        cout<<"Enter n m:"<<endl;
    cin>>n>>m;

    if(SHOW_PROMPTS)
        cout<<"Enter m edges: start end weight"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        adj[start].push_back({weight,end});
        adj[end].push_back({weight,start});
    }

    if(SHOW_PROMPTS)
        cout<<"Enter starting node:"<<endl;
    /// INPUT CHANGE: question-e source thakle input theke nibe.
    int start;
    cin>>start;

    if(SHOW_PROMPTS)
        cout<<"Maximum spanning tree weight: ";
    cout<<prims(start)<<endl;
}
--- ALTERNATIVE MAIN END ---
*/

/// QUESTION: One destination-er shortest distance o path.
/// ALGORITHM: Bellman-Ford + Parent Array
/// CHANGE 1: All nodes-er bodole destination distance/path output.
/// CHANGE 2: Necessary correction: unreachable start theke relax bad.
/// CHANGE 3: Reachable negative cycle hole status diye stop; invalid shortest values/path print hoy na.

#include<iostream>
#include<vector>
using namespace std;

const bool SHOW_PROMPTS=true; /// Practice: true; question-er exact output: false.

int node_count;
int dist[1000];
int parent[1000];
bool is_negCycle;
/// pair<weight,pair<start,end>>
vector<pair<int,pair<int,int>>>edges;

void initialize(int source)
{
    for(int i=0;i<=node_count;i++)
    {
        dist[i]=100000000;
        parent[i]=i;
    }

    dist[source]=0;
}

bool relax(int start,int _end,int weight)
{
    /// CORRECTION: source theke unreachable node diye relax kora jabe na.
    if(dist[start]!=100000000 && dist[_end]>dist[start]+weight)
    {
        dist[_end]=dist[start]+weight;
        parent[_end]=start;
        return true;
    }

    return false;
}

void bellman_ford()
{
    for(int i=0;i<node_count-1;i++)
    {
        for(auto edge:edges)
        {
            int start=edge.second.first;
            int _end=edge.second.second;
            int weight=edge.first;
            relax(start,_end,weight);
        }
    }

    is_negCycle=false;
    for(auto edge:edges)
    {
        int start=edge.second.first;
        int _end=edge.second.second;
        int weight=edge.first;

        if(relax(start,_end,weight)==true)
            is_negCycle=true;
    }
}

int main()
{
    int m;
    if(SHOW_PROMPTS)
        cout<<"Enter node_count m:"<<endl;
    cin>>node_count>>m;

    if(SHOW_PROMPTS)
        cout<<"Enter m directed edges: start end weight"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        edges.push_back({weight,{start,end}});
    }

    if(SHOW_PROMPTS)
        cout<<"Enter source and destination:"<<endl;
    int source,destination;
    cin>>source>>destination;

    initialize(source);
    bellman_ford();

    if(is_negCycle==true)
    {
        cout<<"There is a negative cycle"<<endl;
        return 0;
    }

    if(SHOW_PROMPTS)
        cout<<"Minimum distance: ";
    cout<<dist[destination]<<endl;
    if(dist[destination]==100000000)
    {
        cout<<"No path"<<endl;
    }
    else
    {
        vector<int>path;
        int node=destination;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);

        if(SHOW_PROMPTS)
            cout<<"Path: ";
        for(int i=(int)path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;
    }
}

/*
CURRENT INPUT (uporer active main-er input):
node_count m
m line: start end weight
source destination

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Reachable negative cycle status, othoba destination distance + path.
Unreachable: 100000000 then No path.

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format: node_count m source destination; tarpor m weighted edges.
CHANGE: source o destination first line-e; edge list-er pore abar porbe na.

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    int m;
    if(SHOW_PROMPTS)
        cout<<"Enter node_count m source destination:"<<endl;
    /// INPUT CHANGE 1: source/destination first line-e.
    int source,destination;
    cin>>node_count>>m>>source>>destination;

    if(SHOW_PROMPTS)
        cout<<"Enter m directed edges: start end weight"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        edges.push_back({weight,{start,end}});
    }

    /// INPUT CHANGE 2: source o destination age pora hoyeche.

    initialize(source);
    bellman_ford();

    if(is_negCycle==true)
    {
        cout<<"There is a negative cycle"<<endl;
        return 0;
    }

    if(SHOW_PROMPTS)
        cout<<"Minimum distance: ";
    cout<<dist[destination]<<endl;
    if(dist[destination]==100000000)
    {
        cout<<"No path"<<endl;
    }
    else
    {
        vector<int>path;
        int node=destination;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);

        if(SHOW_PROMPTS)
            cout<<"Path: ";
        for(int i=(int)path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;
    }
}
--- ALTERNATIVE MAIN END ---
*/

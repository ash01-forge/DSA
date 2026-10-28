/// QUESTION: Mandatory indexed edges rekhe minimum total cost.
/// ALGORITHM: Kruskal Minimum Spanning Tree + DSU
/// CHANGE 1: First line n m k; mandatory original 0-based indices sorting-er age process.
/// CHANGE 2: Mandatory weight cost-e include.
/// CHANGE 3: Remaining edges choto theke boro.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const bool SHOW_PROMPTS=true; /// Practice: true; question-er exact output: false.

int _parent[1000];
int _rank[1000];
int n;
int m;

void initialize()
{
    for(int i=0;i<=n;i++)
    {
        _parent[i]=i;
        _rank[i]=0;
    }
}

int find(int x)
{
    if(_parent[x]==x)
        return x;
    else
        return find(_parent[x]);
}

bool union_sets(int x,int y)
{
    int rootx=find(x);
    int rooty=find(y);

    if(rootx!=rooty)
    {
        if(_rank[rootx]==_rank[rooty])
        {
            _parent[rooty]=rootx;
            _rank[rootx]++;
        }
        else if(_rank[rootx]>_rank[rooty])
            _parent[rooty]=rootx;
        else
            _parent[rootx]=rooty;

        return true;
    }

    return false;
}

/// pair<weight,pair<start,end>>
vector<pair<int,pair<int,int>>>edges;

int main()
{
    int k;
    if(SHOW_PROMPTS)
        cout<<"Enter n m k:"<<endl;
    cin>>n>>m>>k;

    if(SHOW_PROMPTS)
        cout<<"Enter m edges: start end cost"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        edges.push_back({weight,{start,end}});
    }

    initialize();
    int cost=0;

    if(SHOW_PROMPTS)
        cout<<"Enter k mandatory edge indices (0-based):"<<endl;
    for(int i=0;i<k;i++)
    {
        int route_number;
        cin>>route_number;

        /// CHANGE: original edge index; ekhono sort kora hoyni.
        int weight=edges[route_number].first;
        int start=edges[route_number].second.first;
        int end=edges[route_number].second.second;

        union_sets(start,end);
        cost+=weight;
    }

    sort(edges.begin(),edges.end());

    for(int i=0;i<m;i++)
    {
        int weight=edges[i].first;
        int start=edges[i].second.first;
        int end=edges[i].second.second;

        if(union_sets(start,end)==true)
        {
            cost+=weight;
        }
    }

    if(SHOW_PROMPTS)
        cout<<"Minimum total cost: ";
    cout<<cost<<endl;
}

/*
CURRENT INPUT (uporer active main-er input):
n m k
m line: start end cost
k original edge indices (0-based)

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Total cost (mandatory edges included)

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format eki, kintu mandatory edge index 1-based.
CHANGE: route_number input-er por route_number--. Sort-er agei mandatory edges process korbe.

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    int k;
    if(SHOW_PROMPTS)
        cout<<"Enter n m k:"<<endl;
    cin>>n>>m>>k;

    if(SHOW_PROMPTS)
        cout<<"Enter m edges: start end cost"<<endl;
    for(int i=0;i<m;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        edges.push_back({weight,{start,end}});
    }

    initialize();
    int cost=0;

    if(SHOW_PROMPTS)
        cout<<"Enter k mandatory edge indices (1-based):"<<endl;
    for(int i=0;i<k;i++)
    {
        int route_number;
        /// INPUT CHANGE: input index 1..m, vector index 0..m-1.
        cin>>route_number;
        route_number--;

        /// CHANGE: original edge index; ekhono sort kora hoyni.
        int weight=edges[route_number].first;
        int start=edges[route_number].second.first;
        int end=edges[route_number].second.second;

        union_sets(start,end);
        cost+=weight;
    }

    sort(edges.begin(),edges.end());

    for(int i=0;i<m;i++)
    {
        int weight=edges[i].first;
        int start=edges[i].second.first;
        int end=edges[i].second.second;

        if(union_sets(start,end)==true)
        {
            cost+=weight;
        }
    }

    if(SHOW_PROMPTS)
        cout<<"Minimum total cost: ";
    cout<<cost<<endl;
}
--- ALTERNATIVE MAIN END ---
*/

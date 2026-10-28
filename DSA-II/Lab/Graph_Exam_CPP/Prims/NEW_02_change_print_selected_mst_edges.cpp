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

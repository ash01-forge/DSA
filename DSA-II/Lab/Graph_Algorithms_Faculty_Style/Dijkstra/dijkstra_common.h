#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
const bool SHOW_PROMPTS=true;const int INF=100000000;
int n,m;bool visited[1000];vector<pair<int,int>>adj[1000];int dist[1000],parent[1000],node_cost[1000];
void ask(string s){if(SHOW_PROMPTS)cout<<s<<endl;}void label(string s){if(SHOW_PROMPTS)cout<<s;}
void initialize(){for(int i=0;i<=n;i++){dist[i]=INF;parent[i]=-1;visited[i]=false;}}
void read_undirected(string name){ask("Enter m edges: start end "+name);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({w,v});adj[v].push_back({w,u});}}
void read_directed(string name){ask("Enter m directed edges: start end "+name);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({w,v});}}
void dijkstra(int start){priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;pq.push({0,start});while(!pq.empty()){pair<int,int>p=pq.top();pq.pop();int distance=p.first,node=p.second;if(visited[node]==false){visited[node]=true;dist[node]=distance;}for(auto it:adj[node]){int w=it.first,neighbor=it.second,new_distance=distance+w;if(visited[neighbor]==false)pq.push({new_distance,neighbor});}}}
void dijkstra_parent(int start){priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;pq.push({0,start});while(!pq.empty()){pair<int,int>p=pq.top();pq.pop();int distance=p.first,node=p.second;if(visited[node]==false){visited[node]=true;dist[node]=distance;}for(auto it:adj[node]){int w=it.first,neighbor=it.second,new_distance=distance+w;if(visited[neighbor]==false&&new_distance<dist[neighbor]){dist[neighbor]=new_distance;parent[neighbor]=node;pq.push({new_distance,neighbor});}}}}
void print_path(int destination){vector<int>path;int node=destination;while(node!=-1){path.push_back(node);node=parent[node];}for(int i=(int)path.size()-1;i>=0;i--)cout<<path[i]<<" ";cout<<endl;}


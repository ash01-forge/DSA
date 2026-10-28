#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
const bool SHOW_PROMPTS=true;
int n,m;bool visited[1000];vector<pair<int,int>>adj[1000];
void ask(string s){if(SHOW_PROMPTS)cout<<s<<endl;}void label(string s){if(SHOW_PROMPTS)cout<<s;}
void read_graph(){ask("Enter m edges: start end weight");for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({w,v});adj[v].push_back({w,u});}}
int prims(int start){priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;pq.push({0,start});int cost=0;while(!pq.empty()){pair<int,int>p=pq.top();pq.pop();int w=p.first,node=p.second;if(visited[node]==false){visited[node]=true;cost+=w;}for(auto it:adj[node])if(visited[it.second]==false)pq.push({it.first,it.second});}return cost;}


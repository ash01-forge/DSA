#include"dijkstra_common.h"
/// VARIATION: Edge cost + পৌঁছানো node-এর entry fee দিয়ে shortest cost।
/// CHANGE: Pizza-এর মতো +node_cost[neighbor]; source fee count হয় না।
int main(){ask("Enter nodes and edges: N M");cin>>n>>m;read_undirected("travel_cost");ask("Enter node fees 1..N:");for(int i=1;i<=n;i++)cin>>node_cost[i];int s,d;ask("Enter source and destination:");cin>>s>>d;initialize();priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;pq.push({0,s});while(!pq.empty()){auto p=pq.top();pq.pop();int dis=p.first,node=p.second;if(!visited[node]){visited[node]=true;dist[node]=dis;}for(auto it:adj[node]){int neighbor=it.second,nd=dis+it.first+node_cost[neighbor];if(!visited[neighbor])pq.push({nd,neighbor});}}label("Minimum total cost: ");cout<<dist[d]<<endl;}
/* INPUT: N M; M edges; N fees; source destination. OUTPUT: minimum total cost. */


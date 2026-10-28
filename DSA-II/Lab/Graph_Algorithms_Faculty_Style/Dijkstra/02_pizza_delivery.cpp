#include"dijkstra_common.h"
/// QUESTION: Driving time + পৌঁছানো intersection-এর wait timeসহ minimum delivery time।
/// CHANGE: new_distance=distance+weight+node_cost[neighbor]।
int main(){ask("Enter intersections and streets: n m");cin>>n>>m;read_undirected("driving_time");ask("Enter W1...Wn waiting times:");for(int i=1;i<=n;i++)cin>>node_cost[i];initialize();priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;pq.push({0,1});while(!pq.empty()){auto p=pq.top();pq.pop();int d=p.first,node=p.second;if(!visited[node]){visited[node]=true;dist[node]=d;}for(auto it:adj[node]){int neighbor=it.second,nd=d+it.first+node_cost[neighbor];if(!visited[neighbor])pq.push({nd,neighbor});}}label("Minimum delivery time: ");cout<<dist[n]<<endl;}
/* INPUT: n m; m roads; W1...Wn. OUTPUT: minimum time 1 to n. */


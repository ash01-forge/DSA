#include"prims_common.h"
/// VARIATION: Prim's দিয়ে Maximum Spanning Tree total weight।
/// CHANGE: greater min-heap-এর বদলে normal priority_queue max-heap।
int main(){ask("Enter nodes and edges: n m");cin>>n>>m;read_graph();priority_queue<pair<int,int>>pq;pq.push({0,1});int total=0;while(!pq.empty()){pair<int,int>p=pq.top();pq.pop();int w=p.first,node=p.second;if(visited[node]==false){visited[node]=true;total+=w;}for(auto it:adj[node])if(visited[it.second]==false)pq.push({it.first,it.second});}label("Maximum spanning tree weight: ");cout<<total<<endl;}
/* INPUT: n m; m weighted edges. OUTPUT: Maximum Spanning Tree total. */


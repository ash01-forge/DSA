#include"dijkstra_common.h"
/// QUESTION: Node 1 থেকে node n-এর shortest distance। CHANGE: Faculty code; prompts only।
int main(){ask("Enter nodes and edges: n m");cin>>n>>m;read_undirected("weight");initialize();dijkstra(1);label("Shortest distance from 1 to n: ");cout<<dist[n]<<endl;}
/* INPUT: n m; m undirected weighted edges. OUTPUT: dist[n]. */


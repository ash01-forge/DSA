#include"dijkstra_common.h"
/// VARIATION: Directed graph-এ source থেকে destination distance ও path।
/// CHANGE: adj[start]-এ edge; reverse edge নেই।
int main(){ask("Enter nodes and directed edges: N M");cin>>n>>m;read_directed("weight");int s,d;ask("Enter source and destination:");cin>>s>>d;initialize();dijkstra_parent(s);label("Shortest distance: ");cout<<dist[d]<<endl;label("Path: ");print_path(d);}
/* INPUT: N M; M directed edges; source destination. OUTPUT: distance and path. */


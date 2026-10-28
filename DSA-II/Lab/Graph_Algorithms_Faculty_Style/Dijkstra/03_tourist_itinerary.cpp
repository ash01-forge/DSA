#include"dijkstra_common.h"
/// QUESTION: Hotel A থেকে Museum B-এর minimum time এবং exact path।
/// CHANGE: parent[] update এবং reverse path print।
int main(){ask("Enter stops and routes: n m");cin>>n>>m;read_undirected("travel_time");int a,b;ask("Enter Hotel A and Museum B:");cin>>a>>b;initialize();dijkstra_parent(a);label("Minimum travel time: ");cout<<dist[b]<<endl;label("Path: ");print_path(b);}
/* INPUT: n m; m roads; A B. OUTPUT: minimum time and A-to-B path. */


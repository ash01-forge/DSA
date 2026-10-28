#include"bellman_common.h"
/// QUESTION: Directed graph-এ negative edgeসহ shortest values ও negative cycle।
/// CHANGE: Faculty algorithm; complete input/call/output এবং prompts যোগ।
int main(){int m;ask("Enter nodes and directed edges: N M");cin>>node_count>>m;read_edges(m,"weight");int s;ask("Enter source:");cin>>s;initialize(s);bellman_ford();if(is_negCycle)cout<<"There is a negative cycle"<<endl;print_dist();}
/* INPUT: N M; M directed edges; source. OUTPUT: cycle status and all distances. */


#include"dijkstra_common.h"
/// QUESTION: A থেকে K shelters-এর মধ্যে nearest shelter, time ও path।
/// CHANGE: One B-এর বদলে K-list; Dijkstra একবার; dist[] scan।
int main(){ask("Enter towns and roads: N M");cin>>n>>m;read_undirected("travel_time");int a,k;ask("Enter A and K:");cin>>a>>k;vector<int>shelters;ask("Enter K shelter nodes:");for(int i=0;i<k;i++){int x;cin>>x;shelters.push_back(x);}initialize();dijkstra_parent(a);int best=shelters[0];for(int i=1;i<k;i++)if(dist[shelters[i]]<dist[best])best=shelters[i];label("Minimum evacuation time: ");cout<<dist[best]<<endl;label("Selected shelter: ");cout<<best<<endl;label("Path: ");print_path(best);}
/* SAMPLE: N=6,M=7; A K=1 2; shelters=4 6. OUTPUT: 7 / 4 / 1 3 2 4. */


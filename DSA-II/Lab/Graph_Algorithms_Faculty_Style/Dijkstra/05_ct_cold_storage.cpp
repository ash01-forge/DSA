#include"dijkstra_common.h"
/// QUESTION: Farm A থেকে K facilities-এর মধ্যে minimum shipping cost facility ও path।
/// CHANGE: Wildfire-এর same logic; weight-এর অর্থ shipping cost।
int main(){ask("Enter hubs and routes: N M");cin>>n>>m;read_undirected("shipping_cost");int a,k;ask("Enter farm A and facility count K:");cin>>a>>k;vector<int>f;ask("Enter K facility nodes:");for(int i=0;i<k;i++){int x;cin>>x;f.push_back(x);}initialize();dijkstra_parent(a);int best=f[0];for(int i=1;i<k;i++)if(dist[f[i]]<dist[best])best=f[i];label("Minimum shipping cost: ");cout<<dist[best]<<endl;label("Selected facility: ");cout<<best<<endl;label("Path: ");print_path(best);}
/* SAMPLE: 5 6 edges; A K=1 2; facilities=4 5. OUTPUT: 6 / 4 / 1 2 3 4. */


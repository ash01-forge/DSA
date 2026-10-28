#include"kruskal_common.h"
/// VARIATION: Mandatory 0-based edge indices রেখে minimum total cost।
/// CHANGE: Indexed edges আগে force; তারপর normal ascending Kruskal।
int main(){int k;ask("Enter nodes, edges, mandatory count: N M K");cin>>n>>m>>k;read_edges("cost");initialize();int cost=0;ask("Enter K mandatory indices:");for(int i=0;i<k;i++){int id;cin>>id;int w=edges[id].first,u=edges[id].second.first,v=edges[id].second.second;union_sets(u,v);cost+=w;}sort(edges.begin(),edges.end());for(int i=0;i<m;i++){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))cost+=w;}label("Minimum total cost: ");cout<<cost<<endl;}
/* INPUT: N M K; M weighted edges; K zero-based indices. OUTPUT: minimum total cost. */


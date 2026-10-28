#include"kruskal_common.h"
/// QUESTION: Minimum Spanning Tree-এর maximum edge বের করো।
/// CHANGE: cost sum না করে maximum_edge=max(maximum_edge,w)।
int main(){ask("Enter nodes and edges: n m");cin>>n>>m;read_edges("weight");sort(edges.begin(),edges.end());initialize();int ans=0;for(int i=0;i<m;i++){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))ans=max(ans,w);}label("Maximum edge in MST: ");cout<<ans<<endl;}
/* INPUT: n m; m weighted edges. OUTPUT: largest selected MST edge. */


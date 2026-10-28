#include"kruskal_common.h"
/// QUESTION: Minimum total cost দিয়ে সব node connect করো।
/// ALGORITHM: Kruskal Minimum Spanning Tree + DSU.
/// CHANGE: Faculty main code; algorithm change নেই, শুধু practice prompts আছে।
int main(){ask("Enter nodes and edges: n m");cin>>n>>m;read_edges("weight");sort(edges.begin(),edges.end());initialize();int cost=0;for(int i=0;i<m;i++){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))cost+=w;}label("Minimum spanning tree cost: ");cout<<cost<<endl;}
/* INPUT: n m; then m lines u v weight. OUTPUT: MST total cost. */


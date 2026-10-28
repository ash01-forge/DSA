#include"kruskal_common.h"
/// QUESTION: সব city-তে পৌঁছাতে পারা maximum standardized truck weight বের করো।
/// ALGORITHM: Maximum Spanning Tree. CHANGE: বড় থেকে ছোট edge; selected edge-এর minimum track।
int main(){ask("Enter cities and roads: n m");cin>>n>>m;read_edges("weight_limit");sort(edges.begin(),edges.end());initialize();int ans=INF;for(int i=m-1;i>=0;i--){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))ans=min(ans,w);}label("Maximum safe truck weight: ");cout<<ans<<endl;}
/* INPUT: n m; m lines u v weight_limit. OUTPUT: Max-ST-এর minimum selected edge. */


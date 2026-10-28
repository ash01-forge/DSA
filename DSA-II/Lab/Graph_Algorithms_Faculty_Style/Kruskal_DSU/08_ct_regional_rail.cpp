#include"kruskal_common.h"
/// QUESTION: Mandatory indexed corridors রেখে Max-ST-এর weakest capacity বের করো।
/// CHANGE: Forced 0-based indices sort-এর আগে; sum নয়, minimum capacity track।
int main(){int k;ask("Enter towns, corridors, mandatory count: N M K");cin>>n>>m>>k;read_edges("capacity");initialize();int ans=INF;ask("Enter K mandatory indices (0-based):");for(int i=0;i<k;i++){int id;cin>>id;int w=edges[id].first,u=edges[id].second.first,v=edges[id].second.second;union_sets(u,v);ans=min(ans,w);}sort(edges.begin(),edges.end());for(int i=m-1;i>=0;i--){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))ans=min(ans,w);}label("Minimum final capacity: ");cout<<ans<<endl;}
/* SAMPLE: same six edges as Metro; mandatory index 0. OUTPUT: 3. */


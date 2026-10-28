#include"kruskal_common.h"
/// QUESTION: Already-built indexed routes রেখে maximum total bandwidth backbone বানাও।
/// CHANGE: N M K একসাথে; Kটি 0-based edge index sort-এর আগে process; তারপর Max-ST।
int main(){int k;ask("Enter hubs, routes, built routes: N M K");cin>>n>>m>>k;read_edges("bandwidth");initialize();int total=0;ask("Enter K built route indices (0-based):");for(int i=0;i<k;i++){int id;cin>>id;int w=edges[id].first,u=edges[id].second.first,v=edges[id].second.second;union_sets(u,v);total+=w;}sort(edges.begin(),edges.end());for(int i=m-1;i>=0;i--){int w=edges[i].first,u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))total+=w;}label("Total bandwidth capacity: ");cout<<total<<endl;}
/* SAMPLE INPUT: 5 6 1 / edges: 1 2 3,1 3 8,2 3 5,2 4 6,3 5 2,4 5 9 / index 4. OUTPUT: 25. */


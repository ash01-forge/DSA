#include"kruskal_common.h"
/// QUESTION: Free existing links ও একটি required route রেখে minimum total cost বের করো।
/// CHANGE: Existing links free union; required route union+cost; তারপর normal Kruskal।
int main(){ask("Enter islands and possible routes: n m");cin>>n>>m;read_edges("cost");initialize();int cost=0,k;ask("Enter free route count:");cin>>k;ask("Enter free routes: start end");for(int i=0;i<k;i++){int u,v;cin>>u>>v;union_sets(u,v);}int x,y,w;ask("Enter required route: start end cost");cin>>x>>y>>w;union_sets(x,y);cost+=w;sort(edges.begin(),edges.end());for(int i=0;i<m;i++){w=edges[i].first;int u=edges[i].second.first,v=edges[i].second.second;if(union_sets(u,v))cost+=w;}label("Minimum total fiber cost: ");cout<<cost<<endl;}
/* INPUT: n m; m edges; free_count; free pairs; required_start required_end cost. OUTPUT: minimum total cost. */


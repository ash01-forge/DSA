#include"kruskal_common.h"
/// QUESTION: Budget-এর মধ্যে যত link সম্ভব নিয়ে minimum tower count বের করো।
/// CHANGE: Union-এর আগে budget check; শেষে cost নয়, DSU root count।
int main(){ask("Enter islands and routes: n m");cin>>n>>m;read_edges("cost");initialize();int cost=0,k;ask("Enter free route count:");cin>>k;ask("Enter free routes: start end");for(int i=0;i<k;i++){int u,v;cin>>u>>v;union_sets(u,v);}int x,y,w;ask("Enter required route: start end cost");cin>>x>>y>>w;union_sets(x,y);cost+=w;int B;ask("Enter budget B:");cin>>B;sort(edges.begin(),edges.end());for(int i=0;i<m;i++){w=edges[i].first;int u=edges[i].second.first,v=edges[i].second.second;if(find(u)!=find(v)){if(cost+w>B)break;union_sets(u,v);cost+=w;}}int towers=0;for(int i=1;i<=n;i++)if(find(i)==i)towers++;label("Minimum towers needed: ");cout<<towers<<endl;}
/* INPUT: Fiber Network input; then B. OUTPUT: connected component/tower count. */


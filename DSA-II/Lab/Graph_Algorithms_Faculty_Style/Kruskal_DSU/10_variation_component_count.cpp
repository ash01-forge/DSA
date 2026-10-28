#include"kruskal_common.h"
/// VARIATION: Kটি connection দেওয়ার পরে কয়টি separate group আছে।
/// CHANGE: শুধু DSU union; শেষে root count।
int main(){int k;ask("Enter nodes and connections: N K");cin>>n>>k;initialize();ask("Enter K pairs: start end");for(int i=0;i<k;i++){int u,v;cin>>u>>v;union_sets(u,v);}int groups=0;for(int i=1;i<=n;i++)if(find(i)==i)groups++;label("Connected groups: ");cout<<groups<<endl;}
/* INPUT: N K; K pairs. OUTPUT: component count. */


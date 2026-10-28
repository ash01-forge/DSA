#include"bellman_common.h"
/// QUESTION: spending ও reward থেকে resource cost এবং infinite farming cycle।
/// CHANGE: Direct weight input নয়; cost=spending-reward।
int main(){int m;ask("Enter milestones and progressions: N M");cin>>node_count>>m;ask("Enter: start end spending reward");for(int i=0;i<m;i++){int u,v,spending,reward;cin>>u>>v>>spending>>reward;int cost=spending-reward;edges.push_back({cost,{u,v}});}int s;ask("Enter starting milestone:");cin>>s;initialize(s);bellman_ford();if(is_negCycle)cout<<"There is an infinite resource farming cycle"<<endl;print_dist();}
/* INPUT: N M; M lines u v spending reward; source. OUTPUT: status and all costs. */


#include"bellman_common.h"
/// QUESTION: Positive consumption/negative rechargeসহ minimum battery usage।
/// CHANGE: Same Bellman logic; weight-এর অর্থ battery usage।
int main(){int m;ask("Enter cities and roads: N M");cin>>node_count>>m;read_edges(m,"battery_usage");int s;ask("Enter starting city:");cin>>s;initialize(s);bellman_ford();if(is_negCycle)cout<<"There is a negative battery cycle"<<endl;print_dist();}
/* INPUT: N M; M directed battery usages; source. OUTPUT: status and all usages. */


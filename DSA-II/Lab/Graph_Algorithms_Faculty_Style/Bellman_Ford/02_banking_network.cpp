#include"bellman_common.h"
/// QUESTION: Organization network-এর minimum transaction cost ও negative cycle।
/// CHANGE: Directed edges; weight-এর অর্থ net transaction cost।
int main(){int m;ask("Enter organizations and transactions: N M");cin>>node_count>>m;read_edges(m,"net_transaction_cost");int s;ask("Enter starting organization:");cin>>s;initialize(s);bellman_ford();if(is_negCycle)cout<<"There is a negative transaction cycle"<<endl;print_dist();}
/* INPUT: N M; M directed transaction costs; source. OUTPUT: status and all costs. */


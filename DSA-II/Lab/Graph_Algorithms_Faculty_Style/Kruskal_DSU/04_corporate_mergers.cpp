#include"kruskal_common.h"
/// QUESTION: MERGE ও QUERY event chronological order-এ process করো।
/// ALGORITHM: Standard DSU. CHANGE: Edge/sort/cost নেই; operation string input।
int main(){ask("Enter companies and events: n m");cin>>n>>m;initialize();ask("Enter: MERGE A B or QUERY A B");for(int i=0;i<m;i++){string op;int a,b;cin>>op>>a>>b;if(op=="MERGE")union_sets(a,b);else if(op=="QUERY")cout<<(find(a)==find(b)?"YES":"NO")<<endl;}}
/* INPUT: n m; then m event lines. OUTPUT: YES/NO for each QUERY. */


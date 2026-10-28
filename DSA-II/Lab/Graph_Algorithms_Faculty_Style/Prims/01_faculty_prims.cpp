#include"prims_common.h"
/// QUESTION: Prim's দিয়ে MST total cost বের করো। CHANGE: Faculty code; শুধু prompt যোগ।
int main(){ask("Enter nodes and edges: n m");cin>>n>>m;read_graph();label("Minimum spanning tree cost: ");cout<<prims(1)<<endl;}
/* INPUT: n m; m undirected weighted edges. OUTPUT: MST total cost. */


/*
MORE EXAM VARIATION: Cheapest route using at most K edges
Change from teacher's code: Relax for K rounds using a previous-round copy so one round adds one edge.
Input example (numbers only, entered in this order):
3 3
1 2 2
2 3 -5
1 3 1
1 3 2
Expected labeled output: Minimum cost using at most 2 edges: -3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<vector>
using namespace std;
struct Edge { int u,v,w; };
int n,m;
vector<Edge> edges;
int main()
{
    cout << "Enter vertices and directed edges: "; cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        Edge e;
        cout << "Enter directed edge " << i+1 << " as: from to signed_cost: ";
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    int A,B,K;
    cout << "Enter source, destination, and maximum edge count K: ";
    cin >> A >> B >> K;
    const int INF=100000000;
    vector<int> previous(n+1,INF);
    previous[A]=0;
    for(int round=1;round<=K;round++)
    {
        vector<int> current=previous; // keep solutions using fewer edges
        for(Edge e:edges)
            if(previous[e.u]!=INF && current[e.v]>previous[e.u]+e.w)
                current[e.v]=previous[e.u]+e.w;
        // MAIN CHANGE: use previous, not current, for each relaxation round.
        previous=current;
    }
    if(previous[B]==INF) cout << "Result: No route within edge limit.\n";
    else cout << "Minimum cost using at most " << K
              << " edges: " << previous[B] << "\n";
}

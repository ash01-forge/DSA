/*
Corporate MERGE / QUERY operations
Earlier code: Teacher Kruskal DSU functions; remove edge sorting and MST cost.
Input example (type the numbers in this order; prompts appear between entries):
5 6
MERGE 1 2
QUERY 1 3
MERGE 2 3
QUERY 1 3
QUERY 4 5
MERGE 4 5
Expected labeled result:
Query 1,3: NO; Query 1,3: YES; Query 4,5: NO
For an online judge, remove the descriptive cout prompts and labels, then
print exactly the output format stated in the exam question.
*/
#include<iostream>
#include<string>
using namespace std;

int n,m,_parent[1000],_rank[1000];
void initialize()
{
    for(int i=1;i<=n;i++) { _parent[i]=i; _rank[i]=0; }
}
int find(int x)
{
    if(_parent[x]==x) return x;
    return find(_parent[x]); // teacher's find (no path compression)
}
bool union_sets(int x,int y)
{
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return false;
    if(_rank[rootx]==_rank[rooty])
    {
        _parent[rooty]=rootx;
        _rank[rootx]++;
    }
    else if(_rank[rootx]>_rank[rooty]) _parent[rooty]=rootx;
    else _parent[rootx]=rooty;
    return true;
}
int main()
{
    cout << "Enter number of companies and operations: ";
    cin >> n >> m; // m is operation count, not edge count
    initialize();
    for(int i=0;i<m;i++)
    {
        string operation; int A,B;
        cout << "Enter operation " << i+1 << " as MERGE A B or QUERY A B: ";
        cin >> operation >> A >> B;
        if(operation=="MERGE")
        {
            union_sets(A,B); // merge groups; no weights
            cout << "Merge completed for companies " << A << " and " << B << ".\n";
        }
        else if(operation=="QUERY")
        {
            cout << "Connection result for companies " << A << " and " << B
                 << ": " << (find(A)==find(B) ? "YES" : "NO") << "\n";
        }
    }
}

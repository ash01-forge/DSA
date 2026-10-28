/*
MORE EXAM VARIATION: Dynamic MERGE, SIZE, and COUNT commands
Change from teacher's code: Store component sizes and count while processing mixed operations.
Input example (numbers only, entered in this order):
4 5
MERGE 1 2
SIZE 2
COUNT
MERGE 2 3
SIZE 3
Expected labeled output: Size of group containing 2: 2; Number of groups: 3; Size of group containing 3: 3
Learning prompts and labels should be removed for an exact-output judge.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,_parent[1000],_rank[1000],group_size[1000],components;
void initialize()
{
    components=n;
    for(int i=1;i<=n;i++)
    { _parent[i]=i; _rank[i]=0; group_size[i]=1; }
}
int find(int x)
{ if(_parent[x]==x) return x; return find(_parent[x]); }
void union_sets(int x,int y)
{
    int a=find(x),b=find(y);
    if(a==b) return;
    if(_rank[a]<_rank[b]) swap(a,b);
    _parent[b]=a;
    group_size[a]+=group_size[b];
    if(_rank[a]==_rank[b]) _rank[a]++;
    components--;
}
int main()
{
    cout << "Enter vertices and number of operations: "; cin >> n >> m;
    initialize();
    for(int i=0;i<m;i++)
    {
        string op;
        cout << "Enter operation " << i+1 << " (MERGE A B, SIZE A, or COUNT): ";
        cin >> op;
        if(op=="MERGE")
        {
            int A,B; cin >> A >> B; // two vertex IDs
            union_sets(A,B);
            cout << "Merged groups of " << A << " and " << B << ".\n";
        }
        else if(op=="SIZE")
        {
            int A; cin >> A;
            cout << "Size of group containing " << A << ": "
                 << group_size[find(A)] << "\n";
        }
        else if(op=="COUNT")
            cout << "Number of groups: " << components << "\n";
    }
}

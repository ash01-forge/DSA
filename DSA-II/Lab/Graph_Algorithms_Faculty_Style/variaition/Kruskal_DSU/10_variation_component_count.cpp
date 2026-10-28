/// QUESTION: K connections-er por separate group count.
/// ALGORITHM: DSU / Union-Find
/// CHANGE 1: Weighted edges/sort nei; union-er por root count.

#include<iostream>
#include<string>
using namespace std;

const bool SHOW_PROMPTS=true; /// Practice: true; question-er exact output: false.

int _parent[1000];
int _rank[1000];
int n;
int m;

void initialize()
{
    for(int i=0;i<=n;i++)
    {
        _parent[i]=i;
        _rank[i]=0;
    }
}

int find(int x)
{
    if(_parent[x]==x)
        return x;
    else
        return find(_parent[x]);
}

bool union_sets(int x,int y)
{
    int rootx=find(x);
    int rooty=find(y);

    if(rootx!=rooty)
    {
        if(_rank[rootx]==_rank[rooty])
        {
            _parent[rooty]=rootx;
            _rank[rootx]++;
        }
        else if(_rank[rootx]>_rank[rooty])
            _parent[rooty]=rootx;
        else
            _parent[rootx]=rooty;

        return true;
    }

    return false;
}

int main()
{
    int k;
    if(SHOW_PROMPTS)
        cout<<"Enter n k:"<<endl;
    cin>>n>>k;

    initialize();

    if(SHOW_PROMPTS)
        cout<<"Enter k connections: start end"<<endl;
    for(int i=0;i<k;i++)
    {
        int start,end;
        cin>>start>>end;
        union_sets(start,end);
    }

    int groups=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)
            groups++;
    }

    if(SHOW_PROMPTS)
        cout<<"Connected groups: ";
    cout<<groups<<endl;
}

/*
CURRENT INPUT (uporer active main-er input):
n k
k line: start end

CURRENT OUTPUT (SHOW_PROMPTS=false hole):
Connected component count

INPUT VARIATION - shudhu proshne ei format thakle use korbe:
Format: n k; k line: start end weight.
CHANGE: weight-o input nibe, kintu group count-e weight use hoy na.

Nicher puro main() diye uporer active main() replace korbe.
Algorithm-er function o global variables eki thakbe.
Comment-er moddher main() ekhon execute hoy na; duita main ekshathe rakhbe na.

--- ALTERNATIVE MAIN START ---
int main()
{
    int k;
    if(SHOW_PROMPTS)
        cout<<"Enter n k:"<<endl;
    cin>>n>>k;

    initialize();

    if(SHOW_PROMPTS)
        cout<<"Enter k connections: start end weight"<<endl;
    for(int i=0;i<k;i++)
    {
        /// INPUT CHANGE: weighted connection input; group count-e weight lage na.
        int start,end,weight;
        cin>>start>>end>>weight;
        union_sets(start,end);
    }

    int groups=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)
            groups++;
    }

    if(SHOW_PROMPTS)
        cout<<"Connected groups: ";
    cout<<groups<<endl;
}
--- ALTERNATIVE MAIN END ---
*/

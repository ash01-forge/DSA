#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const bool SHOW_PROMPTS=true; /// online judge হলে false করবে
const int INF=100000000;
int _parent[1000],_rank[1000],n,m;
vector<pair<int,pair<int,int>>>edges;

void ask(string s){if(SHOW_PROMPTS) cout<<s<<endl;}
void label(string s){if(SHOW_PROMPTS) cout<<s;}
void initialize(){for(int i=0;i<=n;i++){_parent[i]=i;_rank[i]=0;}}
int find(int x){if(_parent[x]==x)return x;return find(_parent[x]);}
bool union_sets(int x,int y){int rootx=find(x),rooty=find(y);if(rootx!=rooty){if(_rank[rootx]==_rank[rooty]){_parent[rooty]=rootx;_rank[rootx]++;}else if(_rank[rootx]>_rank[rooty])_parent[rooty]=rootx;else _parent[rootx]=rooty;return true;}return false;}
void read_edges(string name){ask("Enter "+to_string(m)+" edges: start end "+name);for(int i=0;i<m;i++){int start,end,weight;cin>>start>>end>>weight;edges.push_back({weight,{start,end}});}}


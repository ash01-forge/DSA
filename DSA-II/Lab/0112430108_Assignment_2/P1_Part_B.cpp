#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 4271;

int _parent[MAX_N + 1];
int _rank[MAX_N + 1];
int n;
int m;

void initialize()
{
    for (int i = 0; i <= n; i++)
    {
        _parent[i] = i;
        _rank[i] = 0;
    }
}

int find(int x)
{
    if (_parent[x] == x)
        return x;
    else
        return find(_parent[x]);
}

bool union_sets(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);

    if (rootx != rooty)
    {
        if (_rank[rootx] == _rank[rooty])
        {
            _parent[rooty] = rootx;
            _rank[rootx]++;
        }
        else if (_rank[rootx] > _rank[rooty])
        {
            _parent[rooty] = rootx;
        }
        else
        {
            _parent[rootx] = rooty;
        }

        return true;
    }

    return false;
}

vector<pair<int, pair<int, int>>> edges;

int main()
{
    int A, B;
    cin >> n >> m >> A >> B;

    initialize();

    for (int i = 0; i < A; i++)
    {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    int X, Y, C;
    cin >> X >> Y >> C;

    union_sets(X, Y);

    int cost = C;

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges.push_back(
            {weight,
             {u, v}});
    }

    sort(
        edges.begin(),
        edges.end());

    for (int i = 0; i < m; i++)
    {
        int weight = edges[i].first;
        int start = edges[i].second.first;
        int _end = edges[i].second.second;

        if (find(start) != find(_end))
        {
            if (cost + weight > B)
            {
                break;
            }

            union_sets(start, _end);
            cost += weight;
        }
    }

    int plants = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            plants++;
        }
    }

    cout << plants << endl;
}
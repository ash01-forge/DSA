#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int fromVertex, toVertex;
    long long edgeWeight;
};

int vertexCount, edgeCount, sourceVertex;
vector<edge> edgeList;
vector<long long> shortestDistances;

void computePaths()
{
    vector<long long> cycleDistances(vertexCount + 1, 0);

    for (int passIndex = 1; passIndex <= vertexCount; passIndex++)
    {
        bool wasUpdated = false;
        for (int edgeIndex = 0; edgeIndex < edgeCount; edgeIndex++)
        {
            int fromVertex = edgeList[edgeIndex].fromVertex;
            int toVertex = edgeList[edgeIndex].toVertex;
            long long edgeWeight = edgeList[edgeIndex].edgeWeight;

            if (cycleDistances[fromVertex] + edgeWeight < cycleDistances[toVertex])
            {
                cycleDistances[toVertex] = cycleDistances[fromVertex] + edgeWeight;
                wasUpdated = true;
                if (passIndex == vertexCount)
                {
                    cout << "Negative cycle detected." << endl;
                    return;
                }
            }
        }
        if (!wasUpdated)
            break;
    }

    const long long infinityDistance = 4000000000000000000LL;
    shortestDistances.assign(vertexCount + 1, infinityDistance);
    shortestDistances[sourceVertex] = 0;

    for (int passIndex = 1; passIndex < vertexCount; passIndex++)
    {
        bool wasUpdated = false;
        for (int edgeIndex = 0; edgeIndex < edgeCount; edgeIndex++)
        {
            int fromVertex = edgeList[edgeIndex].fromVertex;
            int toVertex = edgeList[edgeIndex].toVertex;
            long long edgeWeight = edgeList[edgeIndex].edgeWeight;

            if (shortestDistances[fromVertex] != infinityDistance && shortestDistances[fromVertex] + edgeWeight < shortestDistances[toVertex])
            {
                shortestDistances[toVertex] = shortestDistances[fromVertex] + edgeWeight;
                wasUpdated = true;
            }
        }
        if (!wasUpdated)
            break;
    }

    cout << "No negative cycle detected." << endl;
    for (int toVertex = 1; toVertex <= vertexCount; toVertex++)
    {
        if (toVertex == sourceVertex)
            continue;

        cout << toVertex << " ";
        if (shortestDistances[toVertex] == infinityDistance)
            cout << "unreachable" << endl;
        else
            cout << shortestDistances[toVertex] << endl;
    }
}

int main()
{
    cin >> vertexCount >> edgeCount >> sourceVertex;
    edgeList.resize(edgeCount);

    for (int passIndex = 0; passIndex < edgeCount; passIndex++)
        cin >> edgeList[passIndex].fromVertex >> edgeList[passIndex].toVertex >> edgeList[passIndex].edgeWeight;

    computePaths();
    return 0;
}

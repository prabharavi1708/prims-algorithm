#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 9999;

int main()
{
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, totalCost = 0;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int minCost = INF;
        int from = -1, to = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < minCost)
                    {
                        minCost = cost[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        if (to == -1)
        {
            cout << "Cities cannot all be connected.\n";
            return 0;
        }

        cout << from + 1 << " - " << to + 1
             << " : " << minCost << endl;

        visited[to] = 1;
        totalCost += minCost;
        edges++;
    }

    cout << "Minimum total cost: " << totalCost << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of water distribution points: ";
    cin >> n;

    cout << "Enter number of pipe connections: ";
    cin >> e;

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    cout << "Enter connections (point1 point2 cost):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        cost[u][v] = w;
        cost[v][u] = w;
    }

    vector<bool> visited(n, false);
    visited[0] = true;

    int edges = 0;
    int totalCost = 0;

    cout << "\nMinimum Cost Pipe Connections:\n";

    while (edges < n - 1) {
        int minCost = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Network is disconnected. Cannot connect all points.\n";
            return 0;
        }

        cout << u << " - " << v
             << " : Cost = " << minCost << "\n";

        totalCost += minCost;
        visited[v] = true;
        edges++;
    }

    cout << "\nMinimum Total Installation Cost = "
         << totalCost << "\n";

    return 0;
}

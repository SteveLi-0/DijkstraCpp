#include "Dijkstra.h"

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    vector<list<Edge>> grid_list(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
        grid_list[p1].emplace_back(p2, val);
    }

    int start = 1;
    int end = n;

    Dijkstra dijkstra(grid, grid_list);
    int result;
    bool status = dijkstra.solve(start, end, result);
    cout << result << endl;
    int result_new;
    bool status_new = dijkstra.solve_list(start, end, result_new);
    cout << result_new << endl;
}
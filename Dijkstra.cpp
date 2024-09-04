#include "Dijkstra.h"

Dijkstra::Dijkstra(const vector<vector<int>>& adj_matrix, 
	const vector<list<Edge>>& grid_list) :
	numNode(adj_matrix.size() - 1),
	adj_matrix_(adj_matrix),
	grid_list_(grid_list)
{
}

bool Dijkstra::solve(int start_point, int end_point, int& minDistance)
{
	int n = numNode;
	vector<int> minDist(n + 1, INT_MAX);
	vector<int> visited(n + 1, 0);

	minDist[start_point] = 0;

	for (int i = 1; i <= n; ++i) {
		// 1. find node
		int min_dist = INT_MAX;
		int cur = 1;
		for (int i = 1; i <= n; ++i) {
			if (visited[i] == 0 && minDist[i] < min_dist) {
				min_dist = minDist[i];
				cur = i;
			}
		}

		// 2. visited
		visited[cur] = 1;

		// 3. update
		for (int i = 1; i <= n; ++i) {
			if (visited[i] == 0 && adj_matrix_[cur][i] != INT_MAX && minDist[i] - adj_matrix_[cur][i] > minDist[cur]) {
				minDist[i] = adj_matrix_[cur][i] + minDist[cur];
			}
		}
	}

	if (minDist[end_point] == INT_MAX) {
		return false;
	}
	else {
		minDistance = minDist[end_point];
		return true;
	}
}

struct mycmp {
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second > p2.second;
	}
};

bool Dijkstra::solve_list(int start_point, int end_point, int& minDistance)
{
	int n = numNode;
	vector<int> minDist(n + 1, INT_MAX);
	vector<int> visited(n + 1, 0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
	pq.push(pair<int, int>{start_point, 0});
	minDist[start_point] = 0;

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visited[cur.first]) continue;

		visited[cur.first] = 1;

		for (Edge edge : grid_list_[cur.first]) {
			if (visited[edge.to] == 0 && minDist[cur.first] + edge.val < minDist[edge.to]) {
				minDist[edge.to] = minDist[cur.first] + edge.val;
				pq.push(pair<int, int>{edge.to, minDist[edge.to]});
			}
		}
	}

	if (minDist[end_point] == INT_MAX) {
		return false;
	}
	else {
		minDistance = minDist[end_point];
		return true;
	}
}

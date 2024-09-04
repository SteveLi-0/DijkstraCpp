#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <list>


using namespace std;

struct Edge {
	int to;
	int val;

	Edge(int to_, int val_) : to(to_), val(val_) {}
};

class Dijkstra {
public:
	Dijkstra(const vector<vector<int>>& adj_matrix,
		const vector<list<Edge>>& grid_list);
	bool solve(int start_point, int end_point, int& minDistance);
	bool solve_list(int start_point, int end_point, int& minDistance);
private:
	int numNode;
	vector<vector<int>> adj_matrix_;
	vector<list<Edge>> grid_list_;
};

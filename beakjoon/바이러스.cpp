#include <iostream>
#include <vector>

using namespace std;

void init(int m, vector<int> *graph) {
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int dfs(int start, vector<int> *graph, bool *visit) {
	visit[start] = true;
	int count = 1;
	for (int i = 0; i < graph[start].size(); i++) {
		int y = graph[start][i];
		if (!visit[y]) {
			count += dfs(y,graph,visit);
		}
	}
	return count;
}
int main() {
	int n, m;

	cin >> n >> m;
	if (n < 0 || n > 100) {
		return 0;
	}
	vector<int> graph[101];
	bool visit[101] = {false};

	init(m, graph);
	
	int connectNode = dfs(1, graph, visit);
	cout << connectNode-1;
	
}
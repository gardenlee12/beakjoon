#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makegraph(int m, vector<int> *g) {
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void bfs(int start,vector<int> *g,int *visit) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < g[current].size(); i++) {
			if (visit[g[current][i]] == 0) {
				visit[g[current][i]] = 1;
				q.push(g[current][i]);
			}
		}
	}
}

int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	vector<int> g[1001];
	int visit[1001] = {0};

	makegraph(m, g);

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			bfs(i,g,visit);
			cnt++;
		}
	}
	cout << cnt;
}
#include <iostream>
#include <vector>

using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y, vector<vector<int>> &field, vector<vector<bool>> &visit, int M, int N) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visit[nx][ny] && field[nx][ny] == 1) {
			dfs(nx, ny, field, visit, M, N);
		}
	}
}
int main() {
	int T, M, N, K;
	cin >> T;
	
	while (T--) {
		cin >> M >> N >> K;

		vector<vector<int>> field(M, vector<int>(N, 0));
		vector<vector<bool>> visit(M, vector<bool>(N, false));
		
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1;

		}

		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1 && !visit[i][j]) {
					dfs(i, j, field, visit, M, N);
					count++;
				}
			}
		}
		cout << count << endl;
	}
	

}
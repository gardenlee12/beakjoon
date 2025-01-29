#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int dfs(int x, int y, vector<vector<int>> &arr,vector<vector<bool>> &visit, int m, int n) {
	visit[x][y] = true;
	int size = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visit[nx][ny] && arr[nx][ny] == 0) {
			size += dfs(nx, ny, arr, visit, m, n);
		}
	}
	return size;
}
int main() {
	int m,n,k;
	
	cin >> m >> n >> k;

	vector<vector<int>> arr(m, vector<int>(n,0));
	vector<vector<bool>> visit(m, vector<bool>(n, false));


	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int y = b; y < d; y++) {
			for (int x = a; x < c; x++) {
				arr[y][x] = 1;
			}
		}
		
	}

	int count = 0;
	vector<int> zero_size;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && !visit[i][j]) {
				int size = dfs(i, j, arr, visit, m, n);
				zero_size.push_back(size);
				count++;
			}
		}
	}

	sort(zero_size.begin(),zero_size.end());
	cout << count << endl;
	for (int s : zero_size) {
		cout << s << " ";
	}
}
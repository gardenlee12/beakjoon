#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
	if (a[1] != b[1]) {
		return a[1] > b[1];
	}
	if (a[2] != b[2]) {
		return a[2] > b[2];
	}
	if (a[3] != b[3]) {
		return a[3] > b[3];
	}
	return a[0] < b[0];
}
int main() {
	int n, k;

	cin >> n >> k;
	if (n < 1 || n > 1000) {
		cout << "잘못된 입력입니다.";
		return 0;
	}

	vector<vector<int>> medal(n, vector<int>(4));

	for (int i = 0; i < n; i++) {
		cin >> medal[i][0];
		for (int j = 1; j < 4; j++) {
			cin >> medal[i][j];
		}
	}

	sort(medal.begin(), medal.end(), compare);

	vector<int> ranks(n, 0);
	ranks[0] = 1;
	for (int i = 1; i < n; i++) {
		if (medal[i][1] == medal[i - 1][1] &&
			medal[i][2] == medal[i - 1][2] &&
			medal[i][3] == medal[i - 1][3]) {
			ranks[i] = ranks[i - 1];
		}
		else ranks[i] = i + 1;
	}

	for (int i = 0 ; i < n ; i++){
		if (medal[i][0] == k) {
			cout << ranks[i];
		}
	}
}
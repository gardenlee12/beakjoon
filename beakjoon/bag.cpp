#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	long k;
	cin >> n >> k;
	
	if (n < 0 || n > 100 || k < 0 || k > 100000) {
		return 1;
	}

	vector<long> weight(n);
	vector<long> value(n);

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}

	vector<long> dp(k + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = k; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[k] << endl;
}
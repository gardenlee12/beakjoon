#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	if (n < 1 || n > 300) {
		return 1;
	}
	vector<long long> scores(n);
	vector<long long> f(n);
	vector<long long> g(n);
	vector<long long> h(n);

	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}
	f[0] = scores[0];

	if (n >= 1) {
		f[1] = max(scores[0], scores[1]);
	}
	else if (n >= 2) {
		f[2] = max(scores[0] + scores[2], scores[1]);
		g[2] = scores[0] + scores[2];
		h[2] = scores[0];
	}
	
	for (int i = 3; i < n; i++) {	
		g[i] = h[i - 1] + scores[i];
		h[i] = (max(g[i - 2], h[i - 2])) + scores[i];
	}

	long long result = max( g[n-1], h[n-1]);
	cout << result;
}
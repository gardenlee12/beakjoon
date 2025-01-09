#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int sum = 1;
	cin >> n;
	if (n < 0 || n > 500000) {
		return 1;
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (p[i] > 1000) {
			return 1;
		}
		sum += p[i] - 1;
	}
	cout << sum << endl;
}
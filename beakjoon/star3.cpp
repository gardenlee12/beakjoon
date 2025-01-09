#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n <= 0 || n > 100) {
		return 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			cout << '*';
		}
		cout << "\n";
	}
}
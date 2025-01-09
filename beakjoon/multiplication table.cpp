#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n < 1 || n > 9) {
		return 1;
	}

	for (int i = 1; i < 10; i++) {
		cout << n << " * " << i << " = " << n * i << "\n";
	}
}
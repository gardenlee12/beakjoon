#include <iostream>

using namespace std;

long long Fibonacci(int n){

	if (n == 0) return 0;
	if (n == 1) return 1;

	long long a = 0, b = 1, result = 0;
	for (int i = 2; i <= n; i++) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main() {
	int n;

	cin >> n;

	if (n < 0 || n > 90) {
		return 1;
	}

	cout << Fibonacci(n) << endl;
}
#include <iostream>

using namespace std;

int main() {
	int n, p, gcd, lcm;
	cin >> n >> p;

	if (n <= 0 || n > 10000 || p <= 0 || p > 10000) {
		return 1;
	}
	int a = n, b = p;

	while (b != 0) {	
		int temp = a % b;
		a = b;
		b = temp;
	}
	gcd = a;

	lcm = (n * p) / gcd;

	cout << gcd << endl;
	cout << lcm;
} 
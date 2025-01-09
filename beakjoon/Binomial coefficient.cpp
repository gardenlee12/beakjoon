#include <iostream>

using namespace std;

const long MOD = 1000000007;

long long Factorial(long long n, long long k) {
	long long result = 1;
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	for (long long i = 0; i < k; i++) {
		result = (result * (n - i)) % MOD;
		
	}
}
long long extendedEuclid(long long a, long long b, long long* x, long long* y) {
	if (a == 0) {
		*x = 0, * y = 1;
		return b;
	}
	long long x1, y1;
	long long gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}
long long modinverse(long long a, long long m) {
	long long m0 = m, t, q;
	long long x0 = 0, x1 = 1;

	if (a == 1) return 0;

	while (a > 1) { 
		
	}
}

int main() { 
	long long n, k;
	
	cin >> n >> k;
	if (n < 0 || n > 4000000 || k < 0 || k > n) {
		return 1;
	}
	cout << Factorial(n) / (Factorial(k) * Factorial(n - k));		
}
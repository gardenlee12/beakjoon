#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> isPrime(int n) {
	vector<bool> arr(n + 1, true);
	vector<int> primes;
	for (int i = 2; i < sqrt(n); i++) {
		if (arr[i]) {
			int j = 2;
			while (i * j < n) {
				arr[i * j] = false;
				j++;
			}
		}
	}

	for (int i = 2; i <= n; i++) {	
		if (arr[i]) {
			primes.push_back(i);
		}
	}
	return primes;
}

bool isPalindrome(string s) {
	int size = s.size();

	for (int i = 0; i < size / 2; i++) {
		if (s[i] != s[size - 1 - i]) {
			return false;
		}
	}
	return true;
}

int findpalindrome(int n) {
	int num = n;
	while (1) {
		string numstr = to_string(num);
		if (isPalindrome(numstr) && isPrime(num)) {
			return num;
		}
	}
}
int main() {
	int n;

	cin >> n;
	if (n < 0 || n > 1000000) {
		return 1;
	}

	int result = findpalindrome(n);
}
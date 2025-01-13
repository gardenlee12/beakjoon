#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
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

int findPalindrome(int n) {
	int num = n;
	while (true) {
		if (isPalindrome(to_string(num)) && isPrime(num)) {
			return num;
		}
		num++;
	}
}
int main() {
	int n;
	cin >> n;
	if (n < 0 || n > 1000000) {
		return 1;
	}

	int result = findPalindrome(n);
	cout << result;
}
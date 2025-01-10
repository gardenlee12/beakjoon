#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isPrime(int n) {
	vector<bool> arr(n + 1, true);

	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i < n; i++) {
		if (arr[i]) {
			int j = 2;
			while (i * j < n) {
				arr[i * j] = false;
				j++;
			}
		}
	}
	
	return arr[n];
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
		string numstr = to_string(num);
		if (isPalindrome(numstr) && isPrime(num)) {
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
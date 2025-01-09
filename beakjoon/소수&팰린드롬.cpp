#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


vector<int> primenumber(int n) {
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

bool palindrome(int n) {

}


int main() {
	int n;

	cin >> n;
	if (n < 0 || n > 1000000) {
		return 1;
	}

	vector<int> result = primenumber(n);
	
	for (int prime : result) {
		string numstr = to_string(prime);
		if (palindrome(numstr)) {

		}
	}
}
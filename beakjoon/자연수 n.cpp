#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string result;
	cin >> n;

	if (n <= 0 || n > 100000) {
		return 1;
	}

	for(int i = 1; i <= n; i++) {
		result += to_string(i) + "\n";
	}
	cout << result;
}
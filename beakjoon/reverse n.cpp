#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string result;
	cin >> n;

	if (n < 0 || n > 100000) {
		return 1;
	}
	for (int i = n; i > 0; i--) {
		result += to_string(i) + "\n";
	}
	cout << result;
	
}
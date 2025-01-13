#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	int width = 0;
	int length = 0;

	cin >> n;
	if (n < 0 || n > 100) {
		return 0;
	}

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i].length() != n) {
			return 0;
		}
		for (char c : arr[i]) {
			if (c != '.' && c != 'X') {
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int count = 0;
		
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') {
				count++;
			}
			else {
				if (count >= 2) {
					width++;
				}
				count = 0;
			}
		}
		if (count >= 2) {
			width++;
		}
	}

	for (int j = 0; j < n; j++) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '.') {
				count++;
			}
			else {
				if (count >= 2) {
					length++;
				}
				count = 0;
			}
		}
		if (count >= 2) {
			length++;
		}
	}
	cout << width << " " << length;
}
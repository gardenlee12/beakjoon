#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


int uparrow() {

}

int downarrow() {

}

int upchannel() {

}

int downchannel() {

}

int main() {
	int n;

	cin >> n;
	if (n < 2 || n > 100) {
		cout << "잘못된 입력입니다.";
		return 0;
	}
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i].size() > 10 || any_of(arr[i].begin(), arr[i].end(), [](char ch) {return !isalnum(ch); })) {
			return 0;
		}
	}

}
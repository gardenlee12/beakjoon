#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,x,count = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int sum = arr[left] + arr[right];

		if (sum == x) { 
			count++;
			left++;
			right--;
		}
		else if (sum < x) left++;
		else right--;
	}
	cout << count;
}
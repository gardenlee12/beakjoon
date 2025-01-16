#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 0 || n > 99) {
		cout << "�߸��� �Է��Դϴ�.";
		return 0;
	}
	int original = n;
	vector<int> arr;

	do {
		int tens = n / 10;
		int ones = n % 10;
		int sum = tens + ones;

		n = (ones * 10) + (sum % 10);
		
		arr.push_back(n);
		
	} while (n != original);

	cout << arr.size();
}
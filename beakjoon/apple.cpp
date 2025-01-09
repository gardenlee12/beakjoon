#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int sum = 0;

	cin >> n;
	if (n < 1 || n > 100) {
		return 1;
	}
	vector<int> student(n);
	vector<int> apple(n);

	for (int i = 0; i < n; i++) {

		cin >> student[i] >> apple[i];

		if (student[i] > apple[i]) {
			sum += apple[i];
		}
		else if (apple[i] > student[i]) {
			sum += apple[i] % student[i];
		}
	}
	cout << sum;
}
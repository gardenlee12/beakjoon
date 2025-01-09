#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, a, sum = 0 , min = -1;
	cin >> M;
	cin >> N;

	for (int i = M; i <= N; i++) {
		a = sqrt(i);
		if (a * a == i) {
			sum += i;
			if (min == -1 || i < min)
				min = i;
		}
	}
	if (sum != 0) {
		cout << sum << endl;
	}
	cout << min;
}
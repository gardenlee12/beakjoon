#include <iostream>
#include <vector>

using namespace std;

struct Data {
	int q, p;
};

int main(){
	int n, N;
	
	cin >> n;
	if (n < 0 || n > 100000) {
		return 1;
	}
	vector<int> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		cin >> N;
		int totalPrice = s[i];
		if (N < 0 || N > 1000) {
			return 1;
		}
		Data* arr = new Data[N];
		for (int j = 0; j < N; j++) {
			cin >> arr[j].q >> arr[j].p;
			totalPrice += arr[j].q * arr[j].p;
		}
		cout << totalPrice << endl;
		delete[] arr;
	}

}
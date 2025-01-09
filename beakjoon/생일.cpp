#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct person {
	string name;
	int dd;
	int mm;
	int yyyy;
};

bool compare(person& a, person& b) {
	if (a.yyyy != b.yyyy) {
		return a.yyyy < b.yyyy;
	}
	if (a.mm != b.mm) {
		return a.mm < b.mm;
	}
	if (a.dd != b.dd) {
		return a.dd < b.mm;
	}
}

int main() {
	int n = 0;
	cin >> n;
	vector<person> data(n);
	
	for (int i = 0; i < n; i++) {
		cin >> data[i].name >> data[i].dd >> data[i].mm >> data[i].yyyy;
	}

	sort(data.begin(),data.end(), compare);

	cout << data[n - 1].name << endl;
	cout << data[0].name << endl;

}
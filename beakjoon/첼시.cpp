#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct player {
	long long number;
	string name;
};

bool compare(player a, player b) {
	return a.number > b.number;
}
int main() {
	int n;
	cin >> n;
	vector<string> best;
	while (n--) {
		int p;
		player data[100];
		cin >> p;

		for (int i = 0; i < p; i++) {
			cin >> data[i].number >> data[i].name;
		}
		sort(data, data + p, compare);
		best.push_back(data[0].name);
	}
	
	for (const auto& name : best) {
		cout << name << endl;
	}	
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long n;
	cin >> n;
	if (n < 0 || n > 100000) {
		return 1;
	}

	vector <long> results;

	priority_queue <long> maxheap;
	priority_queue <long, vector<long>, greater<long>> minheap;

	for (int i = 0; i < n; i++) {
		long num;
		cin >> num;
		
		if (num > 10000 || num < -10000) {
			return 1;
		}

		if (maxheap.empty() || num <= maxheap.top()) {
			maxheap.push(num);
		}
		else {
			minheap.push(num);
		}

		if (maxheap.size() > minheap.size() + 1) {
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		else if (minheap.size() > maxheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		results.push_back(maxheap.top());
	} 
	for (long result : results) {
		cout << result << "\n";
	}
}
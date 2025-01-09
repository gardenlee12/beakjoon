#include <iostream>

using namespace std;

class Book {
	int price;
	int add;
public:
	void setprice(int p) {
		price = p;
	}
	
	int getprice() {
		return price;
	}

};

int main() {
	int n, p, total = 0, diff = 0;
	Book b[9];

	cin >> n;
	for (int i = 0; i < 9; i++) {
		cin >> p;
		b[i].setprice(p);
		total += p;
	}
	diff = n - total;
	
	cout << diff;
}
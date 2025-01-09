#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class Term {
	vector<int> unit;
	vector<double> score;
	int sum = 0;
public:

	void add_unit(int c) {
		unit.push_back(c);
		sum += c;
	}

	int get_sumunit() {
		return sum;
	}

	void set_score(double g) {
		score.push_back(g);
	}

	double get_average() {
		double weight_sum = 0;
		for (size_t i = 0; i < score.size(); i++) {
			weight_sum += score[i] * unit[i];
		}
		
		weight_sum = round(weight_sum * 1000.0) / 1000.0;
		double average = weight_sum / sum;
		cout << "weight sum: " << weight_sum << ", average" << average << endl;

		double rounded = round(average/ 0.3) * 0.3;
		cout << "round average" << rounded << endl;
		return rounded;
	}
};
int main() {
	int t, n, c;
	double g;
	
	vector<Term> terms;
	cin >> t;
	if (t < 0) {
		return 1;
	}

	for (int i = 0; i < t; i++) {
		Term a;
		
		cin >> n;
		if (n < 0 || n > 10) {
			return 1;
		}
		for (int j = 0; j < n; j++) {
			cin >> c >> g;
			a.add_unit(c);
			a.set_score(g);
		}
		terms.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		cout << terms[i].get_sumunit() << " " << fixed << setprecision(1) <<terms[i].get_average() << endl;
	}
}
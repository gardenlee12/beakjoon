#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int term, subjects, *unit;
	float* score;
	cin >> term;

	for (int i = 0; i < term; i++) {
		int unitsum = 0;
		float totalscore = 0.0;
		
		cin >> subjects;
		score = new float[subjects];
		unit = new int[subjects];

		for (int j = 0; j < subjects; j++) {
			cin >> unit[j] >> score[j];
			unitsum += unit[j];
			totalscore += unit[j] * score[j];
		}
		cout << fixed << setprecision(1) << unitsum << " " << totalscore / unitsum << endl;
		delete[] score;
		delete[] unit;
	}	
}
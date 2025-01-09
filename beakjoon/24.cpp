#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Time {
	int hours, minutes, seconds;

	bool validation() const {
		return (hours >= 0 && hours < 24) &&
			(minutes >= 0 && minutes < 60) &&
			(seconds >= 0 && seconds < 60);
	}

	int to_seconds() const {
		return hours * 3600 + minutes * 60 + seconds;
	}
	
	static Time from_seconds(int total_sceonds) {
		Time t;
		t.hours = total_sceonds / 3600;
		total_sceonds %= 3600;
		t.minutes = total_sceonds / 60;
		t.seconds = total_sceonds % 60;
		return t;
	}

	void printtime() const{
		cout << setfill('0') << setw(2) << hours << ":"
			<< setfill('0') << setw(2) << minutes << ":"
			<< setfill('0') << setw(2) << seconds << endl;
	}
};


int main() {
	Time t1 = { 00, 00, 00 };
	Time t2 = { 00, 00, 00 };

	string time1, time2;
	
	cin >> time1 >> time2;

	stringstream ss1(time1), ss2(time2);
	char delimiter;

	ss1 >> t1.hours >> delimiter >> t1.minutes >> delimiter >> t1.seconds;
	ss2 >> t2.hours >> delimiter >> t2.minutes >> delimiter >> t2.seconds;
	
	if (!t1.validation() || !t2.validation()) {
		return 1;
	}
	
	int t1_seconds = t1.to_seconds();
	int t2_seconds = t2.to_seconds();
	int diff_seconds;
	if (t2_seconds > t1_seconds) {
		diff_seconds = t2_seconds - t1_seconds;
	}
	else {
		diff_seconds = (24 * 3600) - t1_seconds + t2_seconds;
	}

	Time diff_time = Time::from_seconds(diff_seconds);
	diff_time.printtime();

}
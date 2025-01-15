#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Card {
	char color;
	int number;
};
bool isConsecutive(const vector<int>& numbers){
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i] != numbers[i - 1] + 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int n = 5;
	vector<Card> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i].color >> cards[i].number;
	}
	unordered_map<int, int> numCount;
	unordered_map<char, int> colorCount;
	vector<int> numbers;

	for (const auto& card : cards) {
		numCount[card.number]++;
		colorCount[card.color]++;
		numbers.push_back(card.number);
	}
	
	sort(numbers.begin(), numbers.end());

	int score = 0;
	// 1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때
	if (colorCount.size() == 1 && isConsecutive(numbers)) {
		score = numbers.back() + 900;
	}// 2. 카드 5장중 4장이 같은 숫자일 때 or 카드 5장중 3장의 숫자가 같고 나머지 2장의 숫자가 같을 때
	else if (numCount.size() == 2) {
		bool foundFour = false, foundThree = false, foundTwo = false;
		int fourCount = 0, threeCount = 0, twoCount = 0;
		for (const auto& card : numCount) {
			if (card.second == 4) {
				foundFour = true;
				fourCount = card.first;
			}
			if (card.second == 3) {
				foundThree = true;
				threeCount = card.first;
			}if (card.second == 2) {
				foundTwo = true;
				twoCount = card.first;
			}
		}
		if (fourCount) {
			score = fourCount + 800;
		} else if (foundThree && foundTwo) {
			score = (threeCount * 10) + twoCount + 700;
		}
	}// 3. 카드 5장의 색이 모두 같을 때
	else if (colorCount.size() == 1) {
		score = numbers.back() + 600;
	}// 4. 카드 5장의 숫자가 연속적일 때
	else if (isConsecutive(numbers)) {
		score = numbers.back() + 500;
	}// 5. 카드 5장중 3장의 숫자가 같을 때 or 카드 5장중 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때
	else if (numCount.size() == 3) {
		vector<int> pairs;
		bool foundThree = false;
		for (const auto& card : numCount) {
			if (card.second == 3) {
				foundThree = true;
				score = card.first + 400;
				break;
			}
			if (card.second == 2) {
				pairs.push_back(card.first);
			}
		}
		if (pairs.size() == 2) {
			sort(pairs.begin(), pairs.end(), greater<int>());
			score = pairs[0] * 10 + pairs[1] + 300;
		}
	} 
	// 6. 카드 5장 중 2장의 숫자가 같을 때
	else if (numCount.size() == 4) {
		for (const auto& card : numCount) {
			if (card.second == 2) {
				score = card.first + 200;
				break;
			}
		}
	}//7. 위의 어떤 경우도 아닌 경우
	else {
		score = numbers.back() + 100;
	}
	cout << score;
}
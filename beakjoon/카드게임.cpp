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
	// 1. ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� ��
	if (colorCount.size() == 1 && isConsecutive(numbers)) {
		score = numbers.back() + 900;
	}// 2. ī�� 5���� 4���� ���� ������ �� or ī�� 5���� 3���� ���ڰ� ���� ������ 2���� ���ڰ� ���� ��
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
	}// 3. ī�� 5���� ���� ��� ���� ��
	else if (colorCount.size() == 1) {
		score = numbers.back() + 600;
	}// 4. ī�� 5���� ���ڰ� �������� ��
	else if (isConsecutive(numbers)) {
		score = numbers.back() + 500;
	}// 5. ī�� 5���� 3���� ���ڰ� ���� �� or ī�� 5���� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� ��
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
	// 6. ī�� 5�� �� 2���� ���ڰ� ���� ��
	else if (numCount.size() == 4) {
		for (const auto& card : numCount) {
			if (card.second == 2) {
				score = card.first + 200;
				break;
			}
		}
	}//7. ���� � ��쵵 �ƴ� ���
	else {
		score = numbers.back() + 100;
	}
	cout << score;
}
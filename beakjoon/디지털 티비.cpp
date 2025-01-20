//이 문제 조금 이상함
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

struct Node {
	string channelName;
	Node* next;

	Node(const string& name) : channelName(name), next(nullptr) {}
};

class DIgitalTV {
private:
	Node* head;
	Node* tail;
	Node* cursor;
public:
	DIgitalTV() : head(nullptr), cursor(nullptr) {}

	void addChannel(const string& name) {
		Node* newNode = new Node(name);
		if (!head) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		cursor = head;
	}

	void movedown() {
		if (cursor) {
			cursor = cursor->next;
			cout << "1";
		}
	}

	void moveup() {
		if (!cursor || !head) return;
		Node* temp = head;
		while (temp->next != cursor && temp->next != nullptr) {
			temp = temp->next;
		}
		cursor = temp;
		cout << "2";
	}

	

	void swapdown() {
		if (!cursor || !cursor->next) return;
		swap(cursor->channelName, cursor->next->channelName);
		cursor = cursor->next;
		cout << "3";
	}

	void swapup() {
		if (!cursor || cursor == head) return;
		Node* prev = head;
		while (prev->next != cursor) {
			prev = prev->next;
		}
		swap(prev->channelName, cursor->channelName);
		cursor = prev;
		cout << "4";
	}

	

	void movekbs1() {
		do {
			movedown(); 
			if (cursor == head) break;
		} while (cursor->channelName != "KBS1" && cursor != head);

		while (cursor != head) {
			swapup();
		}
	}

	void movekbs2() {
		do {
			movedown();
			if (cursor == head) break;
		} while (cursor->channelName != "KBS2" && cursor != head);

		while (cursor != head->next) {
			swapup();
		}
	}
	~DIgitalTV() {
		if (!head) return;

		Node* temp = head;
		while (temp != nullptr) {
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}

		head = nullptr;
		tail = nullptr;
		cursor = nullptr;
	}
};

int main() {
	int n;

	cin >> n;
	if (n < 2 || n > 100) {
		cout << "잘못된 입력입니다.";
		return 0;
	}
	DIgitalTV tv;

	for (int i = 0; i < n; i++) {
		string channelName;
		cin >> channelName;
		tv.addChannel(channelName);
	}

	tv.movekbs1();
	tv.movekbs2();

}
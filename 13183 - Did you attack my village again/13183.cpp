#include<iostream>
#include<string>
using namespace std;
class Chain;
class Node {
	friend class Chain;
private:
	long long x;
	Node *next, *prev;
public:
	Node(long long x) :x(x) { next = prev = NULL; }
};
class Chain {
private:
	Node *DummyHead;
	void InsertNext(Node*, long long);
	void DeleteNext(Node*);
public:
	Chain() {
		DummyHead = new Node(0);
		DummyHead->next = DummyHead->prev = DummyHead;
	}
	void Insert(long long);
	void Bomb(long long, long long);
	void PrintFront();
	void PrintEnd();
};
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, x, d;
	string s;
	cin >> n;
	Chain chain;
	while (n--) {
		cin >> s;
		if (s == "House") {
			cin >> x;
			chain.Insert(x);
		}
		else if (s == "Bomb") {
			cin >> x >> d;
			chain.Bomb(x, d);
		}
		else if (s == "PrintFront") {
			chain.PrintFront();
		}
		else if (s == "PrintEnd") {
			chain.PrintEnd();
		}
	}
	return 0;
}
void Chain::Insert(long long x) {
	Node *now = DummyHead;
	while (now->next != DummyHead && now->next->x < x) now = now->next;
	if (now->next == DummyHead || now->next->x > x) InsertNext(now, x);
}
void Chain::Bomb(long long x, long long d) {
	int l = x - d, r = x + d;
	Node *now = DummyHead;
	while (now->next != DummyHead && now->next->x <= r) {
		if (now->next->x >= l) DeleteNext(now);
		else now = now->next;
	}
}
void Chain::PrintFront() {
	cout << "PrintFront\n";
	Node *now = DummyHead->next;
	while (now != DummyHead) {
		cout << now->x << '\n';
		now = now->next;
	}
}
void Chain::PrintEnd() {
	cout << "PrintEnd\n";
	Node *now = DummyHead->prev;
	while (now != DummyHead) {
		cout << now->x << '\n';
		now = now->prev;
	}
}
void Chain::InsertNext(Node* node, long long x) {
	Node *tmp = new Node(x);
	tmp->next = node->next;
	tmp->prev = node;
	node->next->prev = tmp;
	node->next = tmp;
}
void Chain::DeleteNext(Node* node) {
	Node *tmp = node->next;
	node->next->next->prev = node;
	node->next = node->next->next;
	delete tmp;
}
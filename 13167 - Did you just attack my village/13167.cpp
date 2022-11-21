#include<iostream>
#include<string>
using namespace std;
class Chain;
class Node {
	friend class Chain;
	friend class HeadNode;
private:
	long long x, y;
	Node *next, *prev;
public:
	Node(long long x, long long y) :x(x), y(y) { next = prev = NULL; }
};
class HeadNode {
	friend class Chain;
private:
	long long y;
	Node *DummyNode;
	HeadNode *nextHead, *prevHead;
	void InsertNode(Node*, long long, long long);
	void DeleteNode(Node*);
public:
	HeadNode(long long y) :y(y) {
		DummyNode = new Node(0, 0);
		DummyNode->next = DummyNode->prev = DummyNode;
		nextHead = prevHead = NULL;
	}
	void Insert(long long, long long);
	void Delete(long long, bool);
	void PrintFront();
	void PrintEnd();
};
class Chain {
private:
	HeadNode *DummyHead;
	void InsertHead(HeadNode*, long long);
	void DeleteHead(HeadNode*);
public:
	Chain() {
		DummyHead = new HeadNode(0);
		DummyHead->nextHead = DummyHead->prevHead = DummyHead;
	}
	void Insert(long long, long long);
	void Bomb(long long, long long);
	void PrintFront();
	void PrintEnd();
};
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, x, y;
	cin >> n;
	string s;
	Chain chain;
	while (n--) {
		cin >> s;
		if (s == "House") { cin >> x >> y; chain.Insert(x, y); }
		else if (s == "Bomb") { cin >> x >> y; chain.Bomb(x, y); }
		else if (s == "PrintFront") { chain.PrintFront(); }
		else if (s == "PrintEnd") { chain.PrintEnd(); }
	}
	return 0;
}
//Chain member function
void Chain::Insert(long long x, long long y) {
	HeadNode *now = DummyHead;
	while (now->nextHead != DummyHead && now->nextHead->y < y) now = now->nextHead;
	if (now->nextHead == DummyHead || now->nextHead->y > y) InsertHead(now, y);
	now->nextHead->Insert(x, y);
}
void Chain::Bomb(long long x, long long y) {
	HeadNode *now = DummyHead;
	while (now->nextHead != DummyHead && now->nextHead->y <= y + 1) {
		now = now->nextHead;
		if (now->y == y) now->Delete(x, true);
		else if (now->y == y - 1) now->Delete(x, false);
		else if (now->y == y + 1) now->Delete(x, false);
	}
}
void Chain::InsertHead(HeadNode* node, long long y) {
	HeadNode *tmp = new HeadNode(y);
	tmp->nextHead = node->nextHead;
	tmp->prevHead = node;
	node->nextHead->prevHead = tmp;
	node->nextHead = tmp;
}
void Chain::DeleteHead(HeadNode* node) {
	HeadNode *tmp = node->nextHead;
	node->nextHead->nextHead->prevHead = node;
	node->nextHead = node->nextHead->nextHead;
	delete tmp;
}
void Chain::PrintFront() {
	cout << "PrintFront\n";
	HeadNode *now = DummyHead->nextHead;
	while (now != DummyHead) {
		now->PrintFront();
		now = now->nextHead;
	}
}
void Chain::PrintEnd() {
	cout << "PrintEnd\n";
	HeadNode *now = DummyHead->prevHead;
	while (now != DummyHead) {
		now->PrintEnd();
		now = now->prevHead;
	}
}
//HeadNode member function
void HeadNode::Insert(long long x, long long y) {
	Node *now = DummyNode;
	while (now->next != DummyNode && now->next->x < x) now = now->next;
	if (now->next == DummyNode || now->next->x > x) InsertNode(now, x, y);
}
void HeadNode::Delete(long long x, bool delete3) {
	Node *now = DummyNode;
	while (now->next != DummyNode && now->next->x <= x + 1) {
		if (now->next->x == x) DeleteNode(now);
		else if (delete3 && now->next->x == x - 1) DeleteNode(now);
		else if (delete3 && now->next->x == x + 1) DeleteNode(now);
		else now = now->next;
	}
}
void HeadNode::InsertNode(Node* node, long long x, long long y) {
	Node *tmp = new Node(x, y);
	tmp->next = node->next;
	tmp->prev = node;
	node->next->prev = tmp;
	node->next = tmp;
}
void HeadNode::DeleteNode(Node* node) {
	Node *tmp = node->next;
	node->next->next->prev = node;
	node->next = node->next->next;
	delete tmp;
}
void HeadNode::PrintFront() {
	Node *now = DummyNode->next;
	while (now != DummyNode) {
		cout << '(' << now->x << ',' << now->y << ')' << '\n';
		now = now->next;
	}
}
void HeadNode::PrintEnd() {
	Node *now = DummyNode->prev;
	while (now != DummyNode) {
		cout << '(' << now->x << ',' << now->y << ')' << '\n';
		now = now->prev;
	}
}
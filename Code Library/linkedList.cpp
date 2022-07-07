#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() {
		val = 0;
		next = NULL;
	}
	ListNode(int n) {
		val = n;
		next = NULL;
	}
	ListNode(int n, ListNode *p)
	{
		val = n;
		next = p;
	}
} *head = NULL;

// Returns size of list
int size()
{
	ListNode *temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// Returns true if the list is empty
bool empty()
{
	return (head == NULL);
}

// Returns value at index (1 - base)
int val_at(int pos)
{
	int i = 1;
	ListNode *temp = head;
	while (temp != NULL)
	{
		if (i == pos)
			return temp->val;
		i++;
		temp = temp->next;
	}
	return -1;
}

// Add val to front
void push_front(int n)
{
	ListNode *newNode = new ListNode(n, head->next);
	head = newNode;
}

// Removes first node and returns value
int pop_front()
{
	int n = head->val;
	head = head->next;
	return n;
}

// Add val to end
void push_back(int n)
{
	ListNode *newNode = new ListNode(n);
	ListNode *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

// Removes end node and returns value
int pop_end()
{
	ListNode *temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
	int n = temp->next->val;
	temp->next = NULL;
	return n;
}

// Returns value at front
int front()
{
	return head->val;
}

// Returns value at end
int end()
{
	ListNode *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return temp->val;
}

// Inserts val at index (1 - base)
void Insert(int pos, int n)
{
	if (pos == 1)
	{
		push_front(n);
		return;
	}
	else if (pos == size())
	{
		push_back(n);
		return;
	}
	ListNode *temp = head;
	int i = 0;
	while (temp != NULL)
	{
		if (i == pos - 1)
			break;
		i++;
		temp = temp->next;
	}

}

// Print the linked list
void Print()
{
	ListNode *temp = head;
	while (temp->next != NULL)
	{
		cout << temp->val << " -> ";
		temp = temp->next;
	}
	cout << temp->val << "\n";
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("err.txt", "w", stderr);
// 	freopen("out.txt", "w", stdout);
// #endif
	cout << "HERE";
	push_front(10);
	Print();
}
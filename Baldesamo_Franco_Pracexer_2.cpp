// Baldesamo_Franco_Pracexer_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
class Node
{
public:

	string name;
	int age{};//new knowledge {} is called array_literal
	Node* left = NULL;
	Node* right = NULL;
};
void getData(Node*& nNode)
{
	nNode = new Node();
	cout << "Enter name: ";
	cin >> nNode->name;
	cout << "Enter age: ";
	cin >> nNode->age;
};
void insertNode(Node*& head, Node*& tail, int pos, Node*& n) {
	if (head == NULL) {
		head = n;
		tail = n;
	}
	else
	{
		if (pos == 1) {
			head->left = n;
			n->right = head;
			head = n;
		}
		else {
			Node* prevNode = head;
			while (prevNode->right != NULL && pos >= 2) {
				prevNode = prevNode->right;
				pos--;
			}
			if (prevNode == tail) {
				n->left = prevNode;
				prevNode->right = n;
				tail = n;
			}
			else {
				prevNode->right/*->left*/ = n;
				n->left = prevNode->right;
				prevNode->right = n;
				n->left = prevNode;
			}
		}
	}
};

void delNode(Node*& head, Node* tail, int pos,Node*& n) {
	if (head == NULL) {
		cout << "The list is empty.";
	}
	else {
		Node* nodeToDel;

		if (pos == 1) {
			nodeToDel = head;

			head = head->right;
			head->left = NULL;
			delete nodeToDel;
		}
		else {
			nodeToDel = head;

			Node* prevNode{};

			while (nodeToDel->right != NULL && pos >= 2) {
				prevNode = nodeToDel;
				nodeToDel = nodeToDel->right;
				pos--;
			}
			if (nodeToDel == tail) {
				prevNode->right = NULL;
				tail = prevNode;
				delete nodeToDel;
			}
			else {
				Node* prevNode{};
				/*prevNode->right = NULL;
				nodeToDel->left = NULL;

				prevNode->right = nodeToDel->right;
				nodeToDel->left = prevNode->right;*/

				/*nodeToDel->right = NULL;*/

				prevNode->right = NULL; 
				prevNode->right = nodeToDel->right;

				nodeToDel->right = NULL;
				nodeToDel->right = prevNode->right;
				/*nodeToDel->right = prevNode->right;*/
				//nodeToDel->right/*->left*/ = prevNode;

				// 
				//
				//nodeToDel->right;

				delete nodeToDel;



			}
				
		}
	}
}
void printDataLR(Node* head) {
	Node* temp = head;
	while (temp != NULL)
	{
		cout << " " << temp->name;
		cout << " " << temp->age << endl;
		temp = temp->right;
	}
};

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* nNode;

	getData(nNode);
	insertNode(head, tail, 1, nNode);

	getData(nNode);
	insertNode(head, tail, 2, nNode);

	getData(nNode);
	insertNode(head, tail, 3, nNode);

	delNode(head, tail, 2, nNode);

	printDataLR(head);
	return 0;
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
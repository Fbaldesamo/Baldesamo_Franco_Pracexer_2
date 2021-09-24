// Baldesamo_Franco_Pracexer_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
class Node
{
public:

	string name;
	int age{};
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
			while (prevNode->right != NULL && pos > 1) {
				prevNode = prevNode->right;
				pos--;
			}
			if (prevNode == tail) {
				n->left = prevNode;
				prevNode->right = n;
				tail = n;
			}
			else {
				prevNode->right = n;
				n->left = prevNode;
			}
		}
	}
};
void delNode(Node*& head, Node* tail, int pos, Node*& n) {
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
			prevNode = head;

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
				prevNode->right = NULL;
				prevNode->right = nodeToDel->right;

				nodeToDel->right = NULL;
				nodeToDel->right = prevNode->right;

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
	string userDEC;
	int userChoice;

	//ask the first 4 input
	getData(nNode);
	insertNode(head, tail, 1, nNode);
	getData(nNode);
	insertNode(head, tail, 2, nNode);
	getData(nNode);
	insertNode(head, tail, 3, nNode);
	getData(nNode);
	insertNode(head, tail, 4, nNode);
	printDataLR(head);
	//if user want to input
	cout << "Do you still want to add input? ";

	cout << "(PLS ANSWER WITH ALL CAPS EX: YES/NO) ";
	cin >> userDEC;
	//repetition if user still want to input

	while (userDEC == "YES") {
		for (int i = 4; i < 10; i++) {
			getData(nNode);
			insertNode(head, tail, i, nNode);
			printDataLR(head);
			cout << "Do you still want to add input? ";
			cin >> userDEC;
			if (userDEC == "NO") {
				break;
			}
		}
	}

	cout << "\nList: \n";
	printDataLR(head);
	cout << "-----------------\n";
	cout << "1-insert";
	cout << "\n2-delete\n";
	cout << "3-EXIT\n";
	cout << "Choice: ";
	cin >> userChoice;

	while (userChoice != 3) {
		if (userChoice == 1) {
			//insert
			int locChoice;
			getData(nNode);
			cout << "What number of location u want to put it? ";
			cin >> locChoice;
			insertNode(head, tail, locChoice, nNode);
			cout << "\nList:\n";
			printDataLR(head);
			cout << "-----------------\n";
			cout << "1-insert";
			cout << "\n2-delete\n";
			cout << "3-EXIT\n";
			cout << "Choice: ";
			cin >> userChoice;
		}
		else if (userChoice == 2) {
			printDataLR(head);

			cout << "What part of list u want to delete? ";
			int locChoice;
			cin >> locChoice;
			delNode(head, tail, locChoice, nNode);
			cout << "After the Deletion:\n";
			printDataLR(head);
		}
	}

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
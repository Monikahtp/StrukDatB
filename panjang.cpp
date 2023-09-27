#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertNode(Node*& head, int data)
{
    Node* nodeBaru = new Node;
    nodeBaru->data = data;
    nodeBaru->next = nullptr;
    if (head == nullptr)
	{
        head = nodeBaru;
    } else {
        Node* current = head;
        while (current->next != nullptr)
		{
            current = current->next;
        }
        current->next = nodeBaru;
    }
}

int main()
{
    Node* head = nullptr;
    int data;
    int hitung = 0;
    while (cin >> data)
	{
        if (data == 0)
		{
            break;
        }
        insertNode(head, data);
        hitung++;
    }
    cout << hitung << endl;

    while (head != nullptr)
	{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
	return 0;
}


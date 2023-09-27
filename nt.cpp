#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void tambahAngka(Node*& head, int bilangan)
{
    Node* newNode = new Node;
    newNode->data = bilangan;
    newNode->next = head;
    head = newNode;
}

void hasilTerbalik(Node* head)
{
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = nullptr; 
    int bilangan;
    std::cout << "Masukkan bilangan (Gunakan bilangan 0 untuk berhenti):" << std::endl;
    while (true)
	{
        std::cin >> bilangan;
        if (bilangan == 0)
		{
            break;
        }
        tambahAngka(head, bilangan);
    }
    
    std::cout << "Output (urutan terbalik):" << std::endl;
    hasilTerbalik(head);

    while (head != nullptr)
	{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}


#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int initialData) {
        data = initialData;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    // Add a value to the end of the list
    void InsertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

};

int main() {
    LinkedList list;
    list.PrintList();

    // Add number
    list.InsertEnd(5);

    // Print the list
    cout << "After adding:" << endl;
    list.PrintList();

    return 0;
}

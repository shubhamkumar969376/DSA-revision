#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* head = nullptr;

// ✅ Recursive Reverse
void reverse(Node* p) {
    // Base case: last node
    if (p->next == nullptr) {
        head = p;
        return;
    }

    reverse(p->next);

    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}

// ✅ Display
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};

    head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < 8; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    cout << "Original List:\n";
    display(head);

    reverse(head);

    cout << "Reversed List:\n";
    display(head);

    return 0;
}

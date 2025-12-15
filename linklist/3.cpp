#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

// ✅ Delete Head
Node* deleteHead(Node* Head) {
    if (Head == NULL) return NULL;

    Node* temp = Head;
    Head = Head->next;
    delete temp;
    return Head;
}

// ✅ Delete Tail
Node* deleteTail(Node* Head) {
    if (Head == NULL || Head->next == NULL) {
        delete Head;
        return NULL;
    }

    Node* temp = Head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return Head;
}

// ✅ Delete Kth Node (1-based index)
Node* deleteKthNode(Node* Head, int k) {
    if (Head == NULL) return NULL;

    if (k == 1) return deleteHead(Head);

    Node* temp = Head;
    for (int i = 1; i < k - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    return Head;
}

// ✅ Delete Kth Node From End
Node* deleteKthNodeFromEnd(Node* Head, int k) {
    Node* fast = Head;
    Node* slow = Head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL) return Head;
        fast = fast->next;
    }

    if (fast == NULL) return deleteHead(Head);

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* del = slow->next;
    slow->next = del->next;
    delete del;

    return Head;
}

// ✅ Display
void display(Node* Head) {
    while (Head != NULL) {
        cout << Head->data << " -> ";
        Head = Head->next;
    }
    cout << "NULL\n";
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};

    Node* Head = new Node(arr[0]);
    Node* temp = Head;

    for (int i = 1; i < 8; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    display(Head);

    Head = deleteHead(Head);
    display(Head);

    Head = deleteTail(Head);
    display(Head);

    Head = deleteKthNode(Head, 3);
    display(Head);

    Head = deleteKthNodeFromEnd(Head, 2);
    display(Head);

    return 0;
}

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

// ✅ Insert at Head
Node* mergeHead(Node* Head, int val) {
    Node* newNode = new Node(val);
    newNode->next = Head;
    return newNode;
}

// ✅ Insert at Tail
Node* mergetail(Node* Head, int val) {
    Node* newNode = new Node(val);

    if (Head == NULL) return newNode;

    Node* temp = Head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return Head;
}

// ✅ Insert at Kth Position (1-based)
Node* mergekthNode(Node* Head, int k, int val) {
    if (k == 1) return mergeHead(Head, val);

    Node* temp = Head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return Head;
}

// ✅ Insert at Kth Position From End
Node* mergekthNodefromend(Node* Head, int k, int val) {
    Node* fast = Head;
    Node* slow = Head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL) return Head;
        fast = fast->next;
    }

    if (fast == NULL) return mergeHead(Head, val);

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* newNode = new Node(val);
    newNode->next = slow->next;
    slow->next = newNode;

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

    Head = mergeHead(Head, 100);
    display(Head);

    Head = mergetail(Head, 200);
    display(Head);

    Head = mergekthNode(Head, 4, 300);
    display(Head);

    Head = mergekthNodefromend(Head, 2, 400);
    display(Head);

    return 0;
}

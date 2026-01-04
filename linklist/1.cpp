#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* arrayToLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]); // first node
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        head->next = new Node(arr[i]); // create new node
        head = head->next;             // move pointer
    }

    return temp;
}
void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToLinkedList(arr, n);
    printLinkedList(head);

    return 0;
}

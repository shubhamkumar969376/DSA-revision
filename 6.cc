#include <bits/stdc++.h>
using namespace std;

// One by one moves qsize elements from front
// to rear of the queue. 
void frontToEndN(queue<int>& q, int qsize)
{
    if (qsize <= 0)
        return;

    // pop front element and push
    // this last in a queue
    q.push(q.front());
    q.pop();

    // Recursive call for pushing element
    frontToEndN(q, qsize - 1);
}

// Function to push an element in the queue with qsize 
void sortedInsert(queue<int>& q, int temp, int qsize)
{
    // Base condition
    if (q.empty() || qsize == 0) {
        q.push(temp);
        return;
    }
    else if (temp <= q.front()) {
        
        // Call stack with front of queue
        q.push(temp);
        
        // One by one move n-1 (old q size
        // elements front to back
        frontToEndN(q, qsize);
    }
    else {
        
        // Push front element into
        // last in a queue
        q.push(q.front());
        q.pop();
        
        // Recursively move all smaller
        // items to back and then insert
        sortedInsert(q, temp, qsize - 1);
    }
}

// Function to sort the given
// queue using recursion
void sortQueue(queue<int>& q)
{
    if (q.empty())
        return;

    // Get the front element which will
    // be stored in this variable
    // throughout the recursion stack
    int temp = q.front();
    
    q.pop();
    
    sortQueue(q);

    // Push the current element into the queue
    // according to the sorting order
    sortedInsert(q, temp, q.size());
}

int main()
{
    queue<int> qu;
    qu.push(10);
    qu.push(7);
    qu.push(16);
    qu.push(9);
    qu.push(20);
    qu.push(5);

    sortQueue(qu);

    while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }
}
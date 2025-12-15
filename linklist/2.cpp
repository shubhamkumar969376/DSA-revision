#include<bits/stdc++.h>
using namespace std;
 class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data,Node*next){
        this->data=data;
        this->next=nullptr;
    }


 };

 int main(){
    Node*temp=new Node(1,nullptr);
    Node*head=temp;
    cout<<temp->data<<endl;

    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<5;i++){

        temp->next =new Node(arr[i],nullptr);
        temp=temp->next;
    }
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }

 }
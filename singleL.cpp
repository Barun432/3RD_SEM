#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node * next;

 Node(int x){
    this->data = x;
    this->next = NULL;
 }
};
// insert at begin......
 void insertAtbegin(Node* &head, Node* tail,int data){
    if(head==NULL && tail==NULL){
          Node*newnode = new Node(data);
        head=newnode;
        tail=newnode;
    } 
    else{
     Node*newnode = new Node(data);
     newnode->next=head;
     head=newnode;
    }
 }
 // insert at end()....
 
void printll(Node*head){
    cout<<"print the linkedlist the Node::"<<endl;
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}


int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node * Third = new Node(30);
    Node * fourth = new Node(40);

    first->next= second;
    second->next= Third;
    Third->next = fourth;
    
    Node *head=first;
    Node *tail = fourth;
    int a,b;
    cin>>a;
    
    cout<<"Enter the choice";
      cin>>b;
    switch (b){
    case 0 : insertAtbegin(head,tail,a);
        break;
    default:
        break;
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node(int data){
      this->data = data;
      this->next = NULL;
 }
 ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node( d);
    temp->next = head;
    head= temp;
}
void insertAtTail(Node* &tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtPosition(Node* tail,Node* head,int position,int d){
    //Insert At Start
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //Insert At Last
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }
    Node* NodetoInsert= new Node(d);
    NodetoInsert->next=temp->next;
    temp->next=NodetoInsert;
}
void print(Node* head){
    Node* temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    

}
void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* current=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
    }
}
int main(){
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
   // cout<<node1->next<<endl;
   Node* head= node1;
   Node*tail=node1;
   print(head);
  //insertAtHead(head,15);
  //insertAtHead(head,16);
  //insertAtHead(head,17);
  insertAtTail(tail,15);
  print(head);
  insertAtTail(tail,16);
  insertAtPosition(tail,head,4,66);
   print(head);
   deleteNode(4,head);
}
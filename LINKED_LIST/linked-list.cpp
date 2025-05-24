#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    
    Node(int val){
      data = val;
      next = nullptr;
    }
};

class LinkedList{
  private:
    Node* head;
  public:
    LinkedList(){
      head = nullptr;
    }
    LinkedList(int data){
      Node* newNode = new Node(data);
      head = newNode;
    }
    
    void printList();
    void insertAtEnd(int val);
    void insertAtBeginning(int val);
    void insertAtAny(int val, int pos);
    
    ~LinkedList(){
      Node* current = head;
      while(current != nullptr){
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
      }
    }
};

int main(){
  LinkedList list_1;
  list_1.insertAtBeginning(19);
  list_1.insertAtEnd(32);
  list_1.insertAtBeginning(97);
  list_1.printList();
  
  LinkedList list_2(3);
  list_2.printList();
  list_2.insertAtEnd(5);
  list_2.insertAtEnd(7);
  list_2.insertAtBeginning(10);
  list_2.insertAtAny(11,5);
  list_2.printList();
  
  return 0;
}

void LinkedList::insertAtAny(int val, int pos){
  if(pos == 1){
    insertAtBeginning(val);
    return;
  }
  if(pos <1){
    cout<<"Index starts from 1."<<endl;
    return;
  }
  
  Node* temp = head;
  int count =1;
  while(temp != nullptr && count < pos-1){
    temp = temp->next;
    count++;
  }
  
  if( temp == nullptr){
    cout<<"out of bound"<<endl;
    return;
  }
  Node* newNode = new Node(val);
  newNode->next = temp->next;
  temp->next = newNode;
}

void LinkedList::insertAtBeginning(int val){
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void LinkedList::printList(){
  Node* temp = head;
  while(temp != nullptr){
    cout<<temp->data;
    cout<<" -> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

void LinkedList::insertAtEnd(int val){
    Node* newNode = new Node(val);
    
  if(head == nullptr){
    head = newNode;
    return;
  }
  
  Node* temp = head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  
  temp->next = newNode;
}
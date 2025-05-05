#include <iostream>
using namespace std;

class Node{
  public:
    int val;
    Node* next;
    
    Node(int data){
      val = data;
      next = NULL;
    }
};

class LinkedList{
  private:
    Node* head;
    
  public:
    
    LinkedList(){
      head = NULL;
    }
    
    void insertAtBeginning(int data);
    
    void insertAtEnd(int data);
    
    void insertAtPosition(int data, int pos);
    
    void printLinkedList();
    
    // Destructor to free memory
    ~LinkedList(){
      Node* temp;
      while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
      }
    }
};

int main(){
  LinkedList list;
  
  list.printLinkedList();
  list.insertAtEnd(5);
  list.printLinkedList();
  list.insertAtBeginning(10);
  list.printLinkedList();
  list.insertAtBeginning(6);
  list.printLinkedList();
  list.insertAtBeginning(12);
  list.printLinkedList();
  list.insertAtBeginning(24);
  list.printLinkedList();
  list.insertAtEnd(1);
  list.printLinkedList();
  list.insertAtEnd(23);
  list.printLinkedList();
  list.insertAtPosition(2, 8);
  list.printLinkedList();
  
  return 0;
}

void LinkedList::insertAtBeginning(int data){
  Node* new_node = new Node(data);
      new_node->next = head;
      head = new_node;
}

void LinkedList::insertAtEnd(int data){
  Node *temp = head;
  Node* new_node = new Node(data);
  
  if(temp == NULL){
    head = new_node;
    return;
  }
  
  while(temp->next != NULL){
    temp = temp->next;
  }
  
  temp->next = new_node;
}

void LinkedList::insertAtPosition(int data, int pos){
  Node *temp = head;
  int trac = 0;
  
  if(pos < 0){
    cout<<"INVALID POSITION!"<<endl;
    return;
  }
  
  if(pos == 0){
    insertAtBeginning(data);
    return;
  }
  
  while((trac < pos-1) && (temp != NULL)){
    trac++;
    temp = temp->next;
  }

  if(trac < pos && temp!= NULL){
    Node *new_node = new Node(data);
    new_node->next = temp->next;
    temp->next = new_node;
  }
  
  if(temp == NULL) cout<<"INVALID POSITION!"<<endl;
}

void LinkedList::printLinkedList(){
  Node *temp = head;
  while(temp != NULL){
    cout<<temp->val<<" -> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}
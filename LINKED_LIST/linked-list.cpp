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
    
    void insertAtBeginning(int data){
      Node* new_node = new Node(data);
      new_node->next = head;
      head = new_node;
    }
    
    void insertAtEnd(int data){
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
    
    void printLinkedList(){
      Node *temp = head;
      while(temp != NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
      }
      cout<<"NULL"<<endl;
    }
    
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
  
  return 0;
}
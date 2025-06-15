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

bool detectCycle(Node* head){
  Node* slow = head;
  Node* fast = head;
  
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    
    if(slow == fast){
      return true;
    }
  }
  
  return false;
}

void printLinkedList(Node* head){
  Node* temp = head;
  while(temp != nullptr){
    cout<<temp->data<<" -> ";
    temp  = temp->next;
  }
  cout<<"NULL"<<endl;;
}

int main(){
  Node* head  = new Node(20);
  Node* second = new Node(21);
  Node* third = new Node(32);
  Node* fourth = new Node(27);
  Node* fifth = new Node(76);
  Node* sixth = new Node(67);
  
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = third;
  
  bool isCycle = detectCycle(head);
  
  if(isCycle){
    cout<<"Loop is present in the LL"<<endl;
  }else{
    cout<<"There is no loop in the LL"<<endl;
    printLinkedList(head);
  }
  
  return 0;
}

// Program Description:
// This program defines a singly linked list and checks if there is a cycle (loop) in the linked list.
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
    void deleteNodeByValue(int val);
    int countNodes();
    void reverse();
    int findMiddle();
    
    ~LinkedList(){
      Node* current = head;
      Node* nextNode = nullptr;
      while(current != nullptr){
        nextNode = current->next;
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
  list_1.deleteNodeByValue(19);
  list_1.printList();
  list_1.deleteNodeByValue(100); // Value does not exist
  cout<<"Number of nodes: "<<list_1.countNodes()<<endl;
  
  cout<<"------------------------"<<endl;
  LinkedList list_2(3);
  list_2.printList();
  list_2.insertAtEnd(5);
  list_2.insertAtEnd(7);
  list_2.insertAtBeginning(10);
  list_2.insertAtAny(11,5);
  list_2.printList();
  list_2.deleteNodeByValue(10);
  list_2.printList();
  cout<<"Number of nodes: "<<list_2.countNodes()<<endl;
 
  
  return 0;
}

int LinkedList::findMiddle(){
  if(head == nullptr){
    cout<<"The list has no nodes."<<endl;
    return -1;
  }
  Node* fast = head;
  Node* slow = head;
  
  while(fast != nullptr && fast->next != nullptr){
    fast = fast->next->next;
    slow = slow->next;
  }
  
  return slow->data;
}

void LinkedList::reverse(){
  Node* prev = nullptr;
  Node* current = head;
  Node* nextNode = nullptr;
  
  while(current != nullptr){
    nextNode = current->next; 
    current->next = prev;     
    prev = current;           
    current = nextNode;       
  }
  
  head = prev; 
}

int LinkedList::countNodes(){
  int count = 0;
  Node* temp = head;
  while(temp != nullptr){
    count++;
    temp = temp->next;
  }
  return count;
}

void LinkedList::deleteNodeByValue(int val){
  if(head == nullptr){
    cout<<"No nodes to delete."<<endl;
    return;
  }
  
  if(head->data == val){
    Node* current = head;
    head = head->next;
    delete current;
    return;
  }
  
  Node* prev = head;
  Node* current = head->next;
  while(current != nullptr){
    if(current->data == val){
      prev->next = current->next;
      delete current;
      return;
    }
    prev = current;
    current = current->next;
  }
  cout<<"Value do not exist."<<endl;
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
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void printArray(int arr[], int size);

int main(){
  int elements[] = {99, 13, 101, 55, 45, 66, 72, 88, 32 , 44, 67, 87, 104, 101, 2};
  int size = sizeof(elements)/sizeof(elements[0]);
  
  
  printArray(elements, size);
  // bubbleSort(elements, size);
  //selectionSort(elements, size);
  insertionSort(elements, size);
  printArray(elements, size);
  
  return 0;
}

void printArray(int arr[], int size){
  cout<<"[";
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"]"<<endl;
}

void bubbleSort(int arr[], int size){
  cout<<"Bubble Sort"<<endl;

  for(int i=0; i<size-1; i++){
    int isSorted = 0;
    for(int j=0; j<size-i-1; j++){
      if(arr[j]> arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        isSorted = 1;
      }
    }
    if(!isSorted) break;
  }
}

void selectionSort(int arr[], int size){
  cout<<"Selection Sort"<<endl;
  
  for(int i=0; i<size-1; i++){
    int minimum = i;
    
    for(int j= (i+1); j<size; j++){
      if(arr[j]< arr[minimum]) minimum = j;
    }
    
    if(minimum != i){
      int temp = arr[minimum];
      arr[minimum] = arr[i];
      arr[i] = temp;
    }
    
  }
}

void insertionSort(int arr[], int size){
  cout<<"Insertion Sort"<<endl;

  for(int i= 1; i<size; i++){
    int insertIdx = i;
    int key = arr[i];
    
    for(int j= i-1; j>=0; j--){
      if(key < arr[j]){
        arr[j+1] = arr[j];
        insertIdx = j;
      }else break;
    }
    arr[insertIdx] = key;
  }
}




// Program Description:
// This program sorts an array using two different sorting algorithms: Bubble Sort and Selection Sort.
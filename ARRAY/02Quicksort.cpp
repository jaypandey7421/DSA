#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high){
  int pivot = arr[high];
  int i = low-1;
  
  for(int j = low; j<high; j++){
    if(arr[j] <= pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  
  swap(arr[i+1], arr[high]);
  
  return i+1;
}

// Function to perform quicksort
void quickSort(vector<int> &arr, int low, int high){
  if(low >= high) return;
  
  int pivotPosition = partition(arr, low, high);
  
  //Left sub-array
  quickSort(arr, low, pivotPosition-1);
  //right sub-array
  quickSort(arr, pivotPosition+1, high);
}

// Function to print the array
void printArray(const vector<int> &arr){
  cout<<"[ ";
  for(auto val: arr){
    cout<<val<<" ";
  }
  cout<<"]"<<endl;
}


int main(){
  vector<int> elements = {10, 3, 19, 2, 20, 22, 30, 9, 10};
  //vector<int> elements = {10};
  
  cout<<"Unsorted array: "<<endl;
  printArray(elements);
  
  quickSort(elements, 0, elements.size() -1);
  
  cout<<"Sorted array: "<<endl;
  printArray(elements);
  
  return 0;
}
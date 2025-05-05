#include <iostream>
#include <algorithm>
using namespace std;

// Function to partition the array
int partition(int arr[], int low , int high){
  int pivot = arr[high];
  int i = low-1;
  
  for(int j=low; j <= high; j++){
    if(arr[j] <= pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  
  return i;
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high){
  if(low >= high) return;
  
  int pivotPosition = partition(arr, low , high);
  // left sub-array
  quickSort(arr, low, pivotPosition-1);
  // right sub-array
  quickSort(arr, pivotPosition+1, high);
}

// Function to print the array
void printArray(int arr[], int size){
  cout<<"[ ";
  
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  
  cout<<"]"<<endl;
}


int main(){
  int elements[] = {10, 5, 0, 11, 20};
  int size = sizeof(elements)/sizeof(elements[0]);
  
  cout<<"Unsorted array: "<<endl;
  printArray(elements, size);
  
  quickSort(elements, 0, size-1);
  
  cout<<"Sorted array: "<<endl;
  printArray(elements, size);
  
  return 0;
}
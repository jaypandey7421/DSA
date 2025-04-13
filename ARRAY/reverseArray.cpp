#include <iostream>

using namespace std;

//Reversing an  array 
void reverse(int arr[], int size){
  int left= 0, right = size - 1;
  int temp;
  
  while(left< right){
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    
    left++;
    right--;
  }
}

//Printing the Array
void printArr(const int arr[], int size){
  cout<<"[";
  for(int i = 0; i< size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"]"<<endl;
}

int main(){
  int elements[] = {20, 10, 2, 10, 33, 12, 11, 9, 1, 7, 71, 32};
  int size = sizeof(elements)/sizeof(elements[0]);
  
  printArr(elements, size);
  reverse(elements, size );
  printArr(elements, size);
  
  
  return 0;
}


// Program Description:
// This program reverses an array in place. It uses two pointers, one starting from the beginning of the array and the other from the end.
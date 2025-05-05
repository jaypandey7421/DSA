#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMax(const vector<int> &arr){
  int max = arr[0];
  for(const int &val: arr){
    if(val > max) max = val;
  }
  
  return max;
}

void printArr(const vector<int> &arr){
  cout<<"[ ";
  for(const int &val: arr){
    cout<<val<<" ";
  }
  cout<<"]"<<endl;
}

void swapArr(vector<int> &original, vector<int> &temp){
  for(int i=0; i<original.size(); i++){
    swap(original[i], temp[i]);
  }
}

void countSort(vector<int> &arr){
  int max = findMax(arr);
  vector<int> temp(arr.size());
  vector<int> frequencyArr(max+1);
  
  //count the frequency of each elements
  for(int &val: arr){
    frequencyArr[val] += 1; 
  }
  
  //count cumulative frequency
  for(int i=1; i<=max; i++){
    frequencyArr[i] += frequencyArr[i-1]; 
  }
  
  
  //final sort 
  int i = static_cast<int>(arr.size())-1;
  for(int j= i ; j>=0; j--){
    // int element = arr[j];
    // frequencyArr[element]--;
    // int elementPos = frequencyArr[element];
    // temp[elementPos] = element;
    temp[frequencyArr[arr[j]]-1] = arr[j];
    frequencyArr[arr[j]]--;
  }
  
  //printArr(temp);
  swapArr(arr, temp);
}

int main(){
  vector<int> elements = {2, 3, 10, 12, 30, 13, 20, 24, 2, 3, 30, 24};
  
  cout<<"Unsorted Array: "<<endl;
  printArr(elements);
  
  countSort(elements);
  
  cout<<"Sorted Array: "<<endl;
  printArr(elements);
  
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr){
  cout<<"[ ";
  for(auto &val: arr){
    cout<<val<<" ";
  }
  cout<<"]"<<endl;
}

void merge(vector<int> &arr, int low, int mid, int high){
  vector<int> temp;
  int left = low; 
  int right = mid+1;
  
  while(left <= mid && right<= high){
    if(arr[left]< arr[right]){
      temp.push_back(arr[left]);
      left++;
    }else{
      temp.push_back(arr[right]);
      right++;
    }
  }
  
  // if elements are remaining in left sub-array
  while(left <= mid){
    temp.push_back(arr[left]);
    left++;
  }
  
  // if elements are remaining in right sub-array  
  while(right<= high){
    temp.push_back(arr[right]);
    right++;
  }
  
  // copying the sorted elements back to original array from temp array
  for(int i=low; i<=high; i++){
    arr[i] = temp[i-low];
  }
}

void mergeSort(vector<int> &arr, int low, int high){
  if(low >= high) return;
  
  int mid = (low+high)/2;
  
  // let sub-array
  mergeSort(arr, low, mid);
  //right sub-array
  mergeSort(arr, mid+1, high);
  //merge 
  merge(arr, low , mid, high);
}

int main(){
  vector<int> elements = {13, 9, 77, 22, 14, 7, 2, 40, 33, 19, 60};
  //vector<int> elements = {13};
  
  cout<<"Original Array: "<<endl;
  printArr(elements);
  mergeSort(elements, 0, elements.size()-1);
  cout<<"Sorted Array: "<<endl;
  printArr(elements);
  
  return 0;
}





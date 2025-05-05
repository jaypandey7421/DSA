#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printArr(const vector<int> &arr);
int findMax(const vector<int> &arr);
void countSort(vector<int> &arr, int devideBy);
void radixSort(vector<int> &arr);

int main(){
  //vector<int> elements = {12, 13, 2, 1, 0, 110, 221, 3345, 99, 199, 10, 59};
  vector<int> elements = {15, 22, 15, 10, 8, 22, 10, 15, 8, 22 };
  
  cout<<"Unsorted array: "<<endl;
  printArr(elements);
  
  radixSort(elements);
  
  cout<<"Sorted array: "<<endl;
  printArr(elements);
  
  return 0;
}


void printArr(const vector<int> &arr){
  cout<<"[ ";
  for(const int &val: arr){
    cout<<val<<" ";
  }
  cout<<"]"<<endl;
}

int findMax(const vector<int> &arr){
  int max = INT_MIN;
  for(const int val: arr){
    if(val > max) max = val;
  }
  return max;
}

void countSort(vector<int> &arr, int devideBy){
  int arrSize = arr.size();
  vector<int> frequencyArr(10, 0);
  vector<int> temp(arrSize, 0);
  
  //calculate the frequency 
  for(int i=0; i<arrSize; i++){
    frequencyArr[(arr[i]/devideBy)%10]++;
  }
  //calculate cumulative frequency
  for(int i=1; i<10; i++){
    frequencyArr[i] += frequencyArr[i-1];
  }
  //putting sorted values to the temp
  for(int i= arrSize-1; i>=0; i--){
    temp[frequencyArr[(arr[i]/devideBy)%10]-1] = arr[i];
    frequencyArr[(arr[i]/devideBy)%10]--;
  }
  //copy values form temp to original array
  for(int i=0; i<arrSize; i++){
    arr[i] = temp[i];
  }
}

void radixSort(vector<int> &arr){
  if(arr.size() < 2) return;
  int max = findMax(arr);
  cout<<"Max: "<<max<<endl;
  
  for(int place = 1; (max/place) > 0; place *= 10){
    countSort(arr, place);
  }
}
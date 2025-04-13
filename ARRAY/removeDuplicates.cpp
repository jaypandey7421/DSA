#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std; 

vector<int> removeDup(const vector<int> &arr);
void rmvDup(vector<int> &arr);
void printArray(const vector<int>  &arr);


int main(){
  vector<int> elements = { 20, 20, 30, 20, 10, 30, 10, 20, 3, 30 , 10, 20 , 30, 9, 3};
  
  printArray(elements);
  vector<int> unique = removeDup(elements);
  printArray(unique);
  rmvDup(elements);
  printArray(elements);
  
  return 0;
}

// Remove duplicates from an Array by using anothere Array.
vector<int> removeDup(const vector<int> &arr){
  vector<int> result;
  unordered_set<int> uniqueCopy;
  
  for(auto &val: arr){
    if(uniqueCopy.find(val) == uniqueCopy.end()){
      uniqueCopy.insert(val);
      result.push_back(val);
    }
  }
  
  return result;
}

// Remove duplicates form an Array without using another Array
void rmvDup(vector<int> &arr){
  
  int size = arr.size();
  
  for(int i=0; i< size; i++){
    for(int j= i+1; j<size; j++){
      if(arr[j] == arr[i]){
        arr[j] = -1;
      }
    }
  }
}

void printArray(const vector<int> &arr){
  cout<<"[";
  for(auto &val: arr){
    if(val != -1) cout<<val<<" ";
  }
  cout<<"]"<<endl;
}


// Program description:
// This program removes duplicates from an array using two different methods:
// 1. By using an additional array to store unique elements.
// 2. By modifying the original array in place, marking duplicates with -1.
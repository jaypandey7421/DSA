#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>     

using namespace std;

void printArr(const vector<float> &arr){
  cout<<"[ ";
  for(float val: arr){
    cout<<val<<" ";
  }
  cout<<"]"<<endl;
}

void bucketSort(vector<float> &arr) {
    int arrSize = arr.size();
    if (arrSize < 2) return;

    // Find minimum and maximum
    float minVal = *min_element(arr.begin(), arr.end());
    float maxVal = *max_element(arr.begin(), arr.end());

    float range = maxVal - minVal;

    // Create buckets
    vector<vector<float>> bucket(arrSize);

    // 3. Distribute elements into buckets
    for (int i = 0; i < arrSize; i++) {
        int index = floor((arr[i] - minVal) / range * (arrSize - 1));
        bucket[index].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < arrSize; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // Copy sorted elements back to original array
    int pos = 0;
    for (vector<float> &list : bucket) {
        for (float val : list) {
            arr[pos++] = val;
        }
    }
}

int main(){
  vector<float> elements = {1.25, 2.33, 0.92, 0.01, 3.01, 0.001, 7.771, 3.32, 2};
  
  cout<<"Unsorted Array: "<<endl;
  printArr(elements);
  
  bucketSort(elements);
  
  cout<<"Sorted Array: "<<endl;
  printArr(elements);
  
  return 0;
}

#include <iostream>
using namespace std;

void simplePyramid(int n);
void flipperSimplePyramid(int n);
void invertedPyramid(int n);
void flippedInvertedPyramid(int n);
void Triangle(int n);

int main(){
  cout<<"           SIMPLE PYRAMID"<<endl;
  simplePyramid(8);
  cout<<"           FLIPPED SIMPLE PYRAMID"<<endl;
  flipperSimplePyramid(8);
  cout<<"           INVERTED PYRAMID"<<endl;
  invertedPyramid(8);
  cout<<"           FLIPPED INVERTED PYRAMID"<<endl;
  flippedInvertedPyramid(8);
  cout<<"           TRIANGLE"<<endl;
  Triangle(8);
  
  return 0;
}

void Triangle(int n){
  for(int i = 1; i<=n; i++){
    for(int j=0; j<(n-i); j++){
      cout<<" ";
    }
    for(int j=0; j<i; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

void flippedInvertedPyramid(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(j<i){
        cout<<" ";
      }else{
        cout<<"*";
      }
    }
    cout<<endl;
  }
}

void simplePyramid(int n){
  for(int i=1; i<=n; i++){
    for(int j=0; j<i; j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

void flipperSimplePyramid(int n){
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<n; j++){
      if(j >= i){
        cout<<"*";
      }else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

void invertedPyramid(int n){
  for(int i=0; i<n; i++){
    for(int j=n-i; j>0; j--){
      cout<<"*";
    }
    cout<<endl;
  }
}
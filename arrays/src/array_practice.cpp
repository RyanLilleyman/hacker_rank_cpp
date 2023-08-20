#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  //printf("Enter the size of the array:");
  int size;
  scanf("%d",&size);
  int arr[size];
  
  for (int i = 0; i < size; i++) {
   // printf("Enter the %i th element",i);
    int entry;
    scanf("%d",&entry);
    arr[i] = entry;
  }

  for (int i = size-1; i >= 0; i--) {
    printf("%d ",arr[i]);
  }
  return 0;
}

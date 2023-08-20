#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int n, q;
  scanf("%d %d",&n,&q);

  std::vector<std::vector<int>> a(n);
   for (int i = 0; i<n; i++) {
    int k;
    scanf("%d",&k);
    std::vector<int> inner(k);
    for (int j = 0; j<k; j++) {
      int inner_entry;
      scanf("%d",&inner_entry);
      inner[j]=inner_entry;
    }
    a[i]=inner;
    printf("\n");
  }

  for (int i = 0; i<q; i++) {
    int first, second;
    scanf("%d %d",&first,&second);
    printf("%d",a[first][second]);
  }
    return 0;
}

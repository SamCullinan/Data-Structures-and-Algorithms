//
//  main.cpp
//  algo
//
//  Created by Самир Новрузов on 15.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort_slow(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void partition3(vector<int> &a, int l, int r ,int &gt, int &lt){
    
    int pivot = a[l];
    gt = r;
    lt = l;
    
    for(int i = l; i <= gt; i++){
        
        if(a[i] < pivot){
            swap(a[i], a[lt]);
            lt++;
        }
        
        else if(a[i] > pivot){

            swap(a[i], a[gt]);
            i--;
            gt--;
        }
    }
}

void randomized_quick_sort(vector<int> &a, int l, int r){
    if (l >= r)
        return;
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    
    int lt;
    int gt;
    
    partition3(a, l, r, lt, gt);

    randomized_quick_sort(a, l, lt - 1);
    randomized_quick_sort(a, gt + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, int(a.size() - 1));
    
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
  }
}

//
//  Task6.h
//  week3
//
//  Created by Самир Новрузов on 13.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//
#pragma once
#ifndef Task6_h
#define Task6_h
void maximum_number_of_prizes(int n) {
  vector<int> prizes;
    
  int k = 0;
  for (int i = 1; n; i++) {
    if (n - i > i) {
      prizes.push_back(i);
      k++;
      n -= i;
    }
    else {
      prizes.push_back(n);
      k++;
      break;
    }
      
  }
    
  cout << k << endl;
  for (auto prize: prizes)
    cout << prize << " ";
}

#endif /* Task6_h */

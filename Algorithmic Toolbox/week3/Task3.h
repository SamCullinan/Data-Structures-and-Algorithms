//
//  Task4.h
//  week3
//
//  Created by Самир Новрузов on 13.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//
#pragma once

#include <iostream>
#include <vector>


int car_fueling(int d, int m, vector<int> & fueling, int start, int count) {
    
    if ((start + m) >= d)
        return count;
    
    if (fueling.size() == 0)
        return -1;
    
    int old_start = start;
    
    for (int i = 0; i < fueling.size(); i++) {
        
        if (fueling[i] <= (start + m)) {
            old_start = fueling[i];
        } else {
    
            if (i != 0)
                fueling.erase(fueling.begin(), fueling.begin() + i);
            else
                fueling.erase(fueling.begin());
            
            return car_fueling(d, m, fueling, old_start, count+1);
        }
    }
    
    return (old_start + m) >= d ? count+1 : -1;
}

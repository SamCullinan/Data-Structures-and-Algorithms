//
//  Task5.h
//  week3
//
//  Created by Самир Новрузов on 13.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//
#pragma once



long long Revenue(vector<int>& profit_per_click, vector<int>& average_number) {
    sort(profit_per_click.begin(), profit_per_click.end());
    sort(average_number.begin(), average_number.end());
    
    long long result = 0;
    
    for (int i = 0; i < profit_per_click.size(); i++) {
        result += (long long) profit_per_click[i] * average_number[i];
    }
    return result;
}



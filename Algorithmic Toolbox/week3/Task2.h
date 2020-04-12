//
//  Task2.h
//  week3
//
//  Created by Самир Новрузов on 12.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//
#pragma once
#ifndef Task2_h
#define Task2_h




int get_best_index(vector<double>& ratios) {
    
    double tmp = 0;
    int best_index = 0;

    for (int i = 0; i < ratios.size(); i++) {
        if (ratios[i] > tmp) {
            tmp = ratios[i];
            best_index = i;
        }
    }
    
    return best_index;
}

void Fractional_Knapsack(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    size_t n = weights.size();
    
    vector<double> ratios(n);
    for(int i=0; i < n;i++) {
        ratios[i] = (double)values[i] / weights[i];
    }
    
    while (capacity > 0 &&  weights.size()!= 0 && values.size()!= 0) {
        
        int best_index = get_best_index(ratios);

        if (weights[best_index] > 0) {
            double a = min((double)capacity, (double)weights[best_index]);
            double ratio = (double) values[best_index] / (double) weights[best_index];
            
            value += a * ratio;
            weights[best_index] -= a;
            capacity -= a;
            
            if (weights[best_index] == 0) {
                weights.erase(weights.begin() + best_index);
                values.erase(values.begin() + best_index);
                ratios.erase(ratios.begin() + best_index);
                
            }
        }
    }
    cout.precision(10);
    cout << value << endl;
}
#endif /* Task2_h */

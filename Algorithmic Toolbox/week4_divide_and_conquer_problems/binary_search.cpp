//
//  main.cpp
//  algo
//
//  Created by Самир Новрузов on 15.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int binary_search(const vector<long long> &num, long long value){
    int left = 0;
    int right = int(num.size());
    while(left<= right){
        int mid = ( left + right )/2;
        if( value == num[mid] )
            return mid;
        else if(value < num[mid])
            right = mid - 1;
        else if(value > num[mid])
            left = mid + 1;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<long long> num1(n);
    
    for(auto& s1: num1)
        cin >> s1;
    
    int m;
    cin >> m;
    vector<long long> num2(m);
    
    for(auto& s2: num2)
        cin >> s2;
    
    for (int i = 0; i < m; ++i)
        cout << binary_search(num1, num2[i]) << " ";
    cout << endl;
    return 0;
}




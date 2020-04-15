//
//  main.cpp
//  algo
//
//  Created by Самир Новрузов on 15.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int countInRange(vector<int> &nums, int num, int lo, int hi) {
    
    int count = 0;
    
    for (int i = lo; i <= hi; i++)
        if (nums[i] == num)
            count++;
        
    return count;
}

int majority_element(vector<int> &nums, int lo, int hi) {
    if(lo == hi)
        return nums[lo];
    
    int mid = (hi-lo)/2 + lo;
    int left = majority_element(nums, lo, mid);
    int right = majority_element(nums, mid+1, hi);
    
    if(left == right)
        return left;
    
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}


int ckeck_element(vector<int> &nums, int ans) {
    int count = 0;
    
    for(auto s: nums)
        if(s == ans)
            count++;
    
    if(count > nums.size()/2)
        return 1;
    
    return 0;
}


int main(){
    
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (auto& num : nums)
        cin>>num;

    int ans = majority_element(nums, 0 , int(nums.size()-1));
    cout << ckeck_element(nums, ans) << '\n';
    
    return 0;
}



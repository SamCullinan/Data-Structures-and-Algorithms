#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using std::cin;
using std::cout;
using std::deque;
using std::max;

void maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int>res;
    deque<int>dq;
        
    for (int i = 0; i < nums.size(); i++) {
            
        while (!dq.empty() && (i - dq.front() >= k))
            dq.pop_front();
            
        while (!dq.empty() && (nums[i] > nums[dq.back()]))
            dq.pop_back();
            
        dq.push_back(i);
            
        if (i >= k-1)
            res.push_back(nums[dq.front()]);
    }
        
    for(auto i : res)
        cout << i <<" ";
    
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    maxSlidingWindow(A, w);
    
    return 0;
}

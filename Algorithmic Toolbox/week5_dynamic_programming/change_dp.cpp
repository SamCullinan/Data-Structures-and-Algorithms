#include <iostream>
#include <vector>


using namespace std;

int get_change(int *coins, const int n, int money) {
    vector<int> arr(money + 1, INT_MAX);
    arr[0] = 0;
    
    for (int i = 1; i <= money; i++)
        for (int c = 0; c < n; c++)
            if (i >= coins[c]) {
                int res = arr[i - coins[c]];
                if (res != INT_MAX && res + 1 < arr[i])
                    arr[i] = res + 1;
            }
    
    return arr[money];
}

int main() {
  
    int money;
    cin >> money;
    const int n = 3;
    int coins[n] = { 1, 3, 4 };
    cout << get_change(coins, n, money) << endl;
    return 0;
}



#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}


int dy_optimal_weight(int W, const vector<int> &w) {
  //write your code here
    auto n = w.size() + 1;
    auto m = W + 1;
    vector<vector<int>> res(n, vector<int>(m,0));
    
    for (size_t i = 1; i < n ; ++i) {
        for (size_t j = 1; j < m; ++j) {
            res[i][j] =  res[i-1][j];
            if(w[i-1] <= j){
                int val =res[i-1][j - w[i-1]] + w[i-1];
                res[i][j] = max(val, res[i][j]);
            }
        }
    }
    
    return res[n-1][m-1];
}


int main() {
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    
    for (int i = 0; i < n; i++)
        cin >> w[i];
    
    cout << dy_optimal_weight(W, w) << '\n';
    return 0;
}

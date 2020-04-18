#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = int(a.size());
    int n = int(b.size());
    int p = int(c.size());
    int length[m+1][n+1][p+1];
 
    for (int i = 0; i<= m; i++) {
        for( int j = 0; j<= n; j++){
            for(int k = 0; k <= p; k++){
            if(i == 0 || j == 0 || k == 0)
                length[i][j][k] = 0;
            else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
                length[i][j][k] = length[i-1][j-1][k-1] + 1;
            else
                length[i][j][k] = max(max(max(max(max(length[i-1][j][k], length[i][j-1][k]), length[i][j][k-1]), length[i-1][j-1][k]), length[i-1][j][k-1]), length[i][j-1][k-1]);
            }
            
        }
    }
    
    return length[m][n][p];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

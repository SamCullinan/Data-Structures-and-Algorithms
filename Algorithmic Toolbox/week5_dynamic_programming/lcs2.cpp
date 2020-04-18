#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    int m = int(a.size());
    int n = int(b.size());
    int length[m+1][n+1];
 
    for (int i = 0; i<= m; i++) {
        for( int j = 0; j<= n; j++){
            if(i == 0 || j == 0)
                length[i][j] = 0;
            else if(a[i-1] == b[j-1])
                length[i][j] = length[i-1][j-1] + 1;
            else
                length[i][j] = max(max(length[i-1][j], length[i][j-1]), length[i-1][j-1]);
            }
            
    }
    
    return length[m][n];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    
    for (size_t i = 0; i < an; i++)
        std::cin >> a[i];
    
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    
    for (size_t i = 0; i < bn; i++)
        std::cin >> b[i];
    
    cout << lcs2(a, b) << std::endl;
    return 0;
}


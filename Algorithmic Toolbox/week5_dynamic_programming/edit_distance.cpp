#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    
    int n = int(str1.size());
    int m = int(str2.size());
    
    vector<vector<int> > distance(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 0; i <= n; ++i)
        distance[i][0] = i;
    
    for(int i = 0; i<= m; ++i)
        distance[0][i] = i;
    
    int cost = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            
            if(str1[i-1] == str2[j-1])
                cost = 0;
            else
                cost = 1;
            
            distance[i][j] = min(min(distance[i-1][j], distance[i][j-1]) + 1, distance[i-1][j-1] + cost);
        }
    }
    return distance[n][m];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}

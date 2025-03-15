#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;

    vector<vector<int>>dp(info.size() + 1, vector<int>(m));
    int suma = 0;
    for (int i = 0; i < info.size(); i++) {
        suma += info[i][0];
        for (int j = 0; j < m; j++) {
            if (j < info[i][1]) {
                dp[i+1][j] = dp[i][j];
            }
            else {
                dp[i+1][j] = max((dp[i][j - info[i][1]] + info[i][0]), dp[i][j]);
            }
        }
    }
    int a = 0;
    a = suma - dp[info.size()][m - 1];
    if (a < n) {
        return a;
    }
    else {
        return -1;
    }

}
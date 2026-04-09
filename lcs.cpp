#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, string> lcs(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result += s1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end());
    return make_pair(dp[m][n], result);
}

int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";

    pair<int, string> result = lcs(s1, s2);
    cout << "LCS Length   : " << result.first  << endl;
    cout << "LCS Sequence : " << result.second << endl;
    // Output: LCS Length   : 4
    //         LCS Sequence : BCAB
    return 0;
}
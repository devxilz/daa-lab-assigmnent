#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printOptimalParens(vector<vector<int>>& bracket, int i, int j) {
    if (i == j) { cout << "M" << i+1; return; }
    cout << "(";
    printOptimalParens(bracket, i, bracket[i][j]);
    printOptimalParens(bracket, bracket[i][j]+1, j);
    cout << ")";
}

int matrixChainOrder(vector<int>& dims) {
    int n = dims.size() - 1;   // number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // chain_len = length of chain being considered
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + dims[i] * dims[k+1] * dims[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j]      = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal parenthesization: ";
    printOptimalParens(bracket, 0, n-1);
    cout << endl;

    return dp[0][n-1];
}

int main() {
    // Matrices: 10x30, 30x5, 5x60, 60x10
    vector<int> dims = {10, 30, 5, 60, 10};
    cout << "Min multiplications: " << matrixChainOrder(dims) << endl;
    // Output: Min multiplications: 27000
    return 0;
}
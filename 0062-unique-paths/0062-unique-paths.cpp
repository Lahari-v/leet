class Solution {
public:
    int uniquePathsRecur(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i >= m || j>= n) 
            return 0;
        else if(i == (m-1) && j == (n-1))
            return 1;
        else if(dp[i][j] != -1)
            return  dp[i][j];
        else
            return dp[i][j] = uniquePathsRecur(m, n, i+1, j, dp) + uniquePathsRecur(m, n, i, j+1, dp);
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return uniquePathsRecur(m, n, 0, 0, dp); 
    }
};
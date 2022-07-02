class Solution {
private:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
    {
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        else
            return dp[i][j] = 0 + max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, s1, s2, dp);
    }
};
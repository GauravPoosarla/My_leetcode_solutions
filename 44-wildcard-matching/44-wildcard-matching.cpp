class Solution {
private:
    bool isAllStars(string& s, int i)
    {
        for(int j=0; j<=i; j++)
        {
            if(s[j] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string& s, string& p, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 and j < 0)
            return true;
        if(i < 0 and j >= 0)
            return isAllStars(p, j);
        if(i >= 0 and j < 0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] or p[j] == '?')
            return dp[i][j] =  isMatch(s, p, i-1, j-1, dp);
        else
        {
            if(p[j] == '*')
                return dp[i][j] = isMatch(s, p, i, j-1, dp) or isMatch(s, p, i-1, j, dp);
            else
                return dp[i][j] = false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return isMatch(s, p, n-1, m-1, dp);
    }
};
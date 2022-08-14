class Solution {
private:
    int f(int index, string& s, vector<int>& dp)
    {
        int n = s.size();
        if(index == n)
            return 1;
        if(s[index] == '0')
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int res = f(index + 1, s, dp);
        if(index < n-1 and (s[index] == '1' or (s[index] == '2' and s[index+1] < '7')))
            res += f(index+2, s, dp);
        return dp[index] = res;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '0')
                dp[i] = 0;
            else
            {
                dp[i] = dp[i+1];
                if(i < n-1 and (s[i] == '1' or (s[i] == '2' and s[i+1] < '7')))
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
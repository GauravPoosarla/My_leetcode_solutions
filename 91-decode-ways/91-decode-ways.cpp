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
        if(index < n-1 and (s[index] == '1' or (s[index] == '2' and s[index+1] <'7')))
            res += f(index+2, s, dp);
        return dp[index] = res;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return f(0, s, dp);
    }
};
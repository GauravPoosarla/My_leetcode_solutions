class Solution {
private:
    bool f(int start, string s, unordered_set<string>& sz, vector<int>& dp)
    {
        int length = s.size();
        if(start >= length)
            return true;
        if(dp[start] != -1)
            return dp[start];
        
        for(int i=start+1; i<=length; i++)
        {
            if(sz.count(s.substr(start, i - start)) and f(i, s, sz, dp))
                return dp[start] = true;
        }
        return dp[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sz;
        int start = 0;
        vector<int> dp(s.size(), -1);
        for(int i=0; i<wordDict.size(); i++)
        {
            sz.insert(wordDict[i]);
        }
        return f(start, s, sz, dp);
    }
};
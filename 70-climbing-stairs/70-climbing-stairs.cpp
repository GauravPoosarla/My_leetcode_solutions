class Solution {
private:
    int f(int index, vector<int>& dp)
    {
        if(index <= 2)
            return index;
        if(dp[index] != -1)
            return dp[index];
        
        int one = f(index-1, dp);
        int two = f(index-2, dp);
        
        return dp[index] = one + two;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            int notPick = 0 + dp[i-1];
            int pick = nums[i];
            if(i > 1)
                pick += dp[i-2];
            dp[i] = max(notPick, pick);
        }
        return dp[n-1];
    }
};
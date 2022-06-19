class Solution {
private:
    int rob(int index, vector<int>& nums, vector<int>& dp)
    {
        if(dp[index] != -1)
            return dp[index];
        if(index == 0)
            return nums[0];
        if(index < 0)
            return 0;
        
        int notPick = 0 + rob(index-1, nums, dp);
        int pick = nums[index];
        if(index > 1)
            pick += rob(index-2, nums, dp);
        
        return dp[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rob(n-1, nums, dp);
    }
};
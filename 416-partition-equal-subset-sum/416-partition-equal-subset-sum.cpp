class Solution {
private:
    bool subsetSum(int index, vector<int>& nums, int target, vector<vector<int>>& dp)
    {
        if(target == 0)
            return true;
        if(index == 0)
            return nums[0] == target;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool notPick = subsetSum(index-1, nums, target, dp);
        
        bool pick = false;
        if(nums[index] <= target)
            pick = subsetSum(index-1, nums, target-nums[index], dp);
        
        return dp[index][target] = pick or notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1)
            return false;
        
        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return subsetSum(nums.size()-1, nums, target, dp);
    }
};
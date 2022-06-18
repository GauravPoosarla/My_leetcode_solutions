class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            mini = min(mini, nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] -= mini;
        }
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};
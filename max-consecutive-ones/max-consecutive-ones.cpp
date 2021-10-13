class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_ones = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count > max_ones)
            {
                max_ones = count;
            }
        }
        return max_ones;
    }
};
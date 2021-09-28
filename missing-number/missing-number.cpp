class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j;
        for(int i=0; i<nums.size();i++)
        {
            j=i;
            if(nums[i] == i)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
        return j+1;
    }
};
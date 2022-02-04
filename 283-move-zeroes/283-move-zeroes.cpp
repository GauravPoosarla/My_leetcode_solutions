class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0;
        int second = 0;
        
        while(first < nums.size())
        {
            if(nums[first] != 0)
            {
                swap(nums[first], nums[second]);
                second++;
            }
            first++;
        }
    }
};
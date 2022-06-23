class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size()-1;
        int n = nums.size();
        
        for(int k = n-1; k>=0; k--)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                result[k] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[k] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};
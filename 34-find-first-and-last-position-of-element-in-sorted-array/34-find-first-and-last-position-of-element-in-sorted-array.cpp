class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = 0;
        int end = nums.size()-1;
        int leftIndex = -1, rightIndex = -1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(nums[mid] == target)
            {
                leftIndex = mid;
                end = mid-1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        result.push_back(leftIndex);
        
        start = 0;
        end = nums.size()-1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(nums[mid] == target)
            {
                rightIndex = mid;
                start = mid+1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        result.push_back(rightIndex);
        return result;
    }
};
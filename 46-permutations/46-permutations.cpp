class Solution {
private:
    void permute(vector<int> nums, int index, vector<vector<int>>& result)
    {
        // base case
        if(index >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        // recursive call
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permute(nums, index+1, result);
            //bactrack
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int index = 0;
        permute(nums, index, result);
        return result;
    }
};
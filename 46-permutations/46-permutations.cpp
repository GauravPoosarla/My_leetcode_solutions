class Solution {
private:
    void permute(vector<int>& nums, vector<vector<int>>& result, int index)
    {
        if(index == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            permute(nums, result, index+1);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int index = 0;
        permute(nums, result, index);
        return result;
    }
};
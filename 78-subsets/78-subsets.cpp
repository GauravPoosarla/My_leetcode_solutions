class Solution {
private:
    void subsets(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, int index)
    {
        if(index == nums.size())
        {
            result.push_back(ds);
            return ;
        }
        ds.push_back(nums[index]);
        subsets(nums, ds, result, index+1);
        ds.pop_back();
        
        subsets(nums, ds, result, index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        subsets(nums, ds, result, 0);
        return result;
    }
};
class Solution {
private:
    void subsetsWithDup(vector<int>nums, int index, vector<int>ds, vector<vector<int>>& result)
    {
        result.push_back(ds);
        for(int i=index; i<nums.size(); i++)
        {
            if(i!=index and nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
            subsetsWithDup(nums, i+1, ds, result);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        int index = 0;
        subsetsWithDup(nums, index, ds, result);
        return result;
    }
};
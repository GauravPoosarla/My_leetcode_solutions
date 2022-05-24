class Solution {
private:
    void subsetsWithDup(vector<int>& nums, int index, vector<int> ds, set<vector<int>>& res)
    {
        if(index == nums.size())
        {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return ;
        }
        ds.push_back(nums[index]);
        subsetsWithDup(nums, index+1, ds, res);
        ds.pop_back();
        subsetsWithDup(nums, index+1, ds, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        set<vector<int>> res;
        subsetsWithDup(nums, 0, ds, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
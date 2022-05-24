class Solution {
private:
    void subsetsWithDup(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, int index)
    {
        result.push_back(ds);
        for(int i=index; i<nums.size(); i++)
        {
            if(i != index and nums[i] == nums[i-1])
                continue;
            
            ds.push_back(nums[i]);
            subsetsWithDup(nums, ds, result, i+1);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, ds, result, 0);
        return result;
    }
};
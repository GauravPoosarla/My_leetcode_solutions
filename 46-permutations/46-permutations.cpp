class Solution {
private:
    void permute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, vector<int>& visited)
    {
        if(ds.size() == nums.size())
        {
            result.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i] == -1)
            {
                ds.push_back(nums[i]);
                visited[i] = 1;
                permute(nums, ds, result, visited);
                visited[i] = -1;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> visited(nums.size(), -1);
        permute(nums, ds, result, visited);
        return result;
    }
};
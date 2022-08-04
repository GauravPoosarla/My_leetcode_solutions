class Solution {
private:
    void combinationSum(vector<int>& candidates, vector<vector<int>>& result, vector<int>& ds, int target, int index)
    {
        if(index == candidates.size())
        {
            if(target == 0)
            {
                result.push_back(ds);
            }
            return ;
        }
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            combinationSum(candidates, result, ds, target-candidates[index], index);
            ds.pop_back();
        }
        combinationSum(candidates, result, ds, target, index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        combinationSum(candidates, result, ds, target, 0);
        return result;
    }
};
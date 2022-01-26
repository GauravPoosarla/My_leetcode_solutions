class Solution {
private:
void combinationSum(vector<int>& candidates, int target, int index, vector<int>& ds, vector<vector<int>>& result)
{
    if(index == candidates.size())
    {
        if(target == 0)
        {
            result.push_back(ds);
        }
        return;
    }
    if(candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        combinationSum(candidates, target - candidates[index], index, ds, result);
        ds.pop_back();
    }
    combinationSum(candidates, target, index+1, ds, result);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        combinationSum(candidates, target, 0, ds, result);
        return result;
    }
};
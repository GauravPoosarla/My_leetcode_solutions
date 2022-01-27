class Solution {
private:
    void combinationSum2(vector<int>& candidates, int target, int index, vector<int> ds, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++)
        {
            if(i > index and candidates[i] == candidates[i-1])
                continue;
            if(target < candidates[i])
                break;
            ds.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], i+1, ds, result);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        int index = 0;
        combinationSum2(candidates, target, index, ds, result);
        return result;
    }
};
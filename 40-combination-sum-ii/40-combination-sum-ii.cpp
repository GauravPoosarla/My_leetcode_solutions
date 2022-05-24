class Solution {
private:
    void combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& ds, int index)
    {
        if(target == 0)
        {
            result.push_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++)
        {
            if(i != index and candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], result, ds, i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        int index = 0;
        
        combinationSum2(candidates, target, result, ds, index);
        return result;
    }
};
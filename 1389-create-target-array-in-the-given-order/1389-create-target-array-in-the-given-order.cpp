class Solution {
public:
    void move(vector<int>& result, int index)
    {
        for(int i=result.size()-1; i>=index+1; i--)
        {
            result[i] = result[i-1];
        }
    }
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> result(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(result[index[i]] == -1)
            {
                result[index[i]] = nums[i];
            }
            else
            {
                move(result, index[i]);
                result[index[i]] = nums[i];
            }
        }
        return result;
    }
};
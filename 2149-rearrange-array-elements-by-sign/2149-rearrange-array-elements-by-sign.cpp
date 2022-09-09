class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int indPos = 0, indNeg = 1;
        
        for(auto num : nums)
        {
            if(num > 0)
            {
                ans[indPos] = num; 
                indPos += 2;
            }
            else
            {
                ans[indNeg] = num; 
                indNeg += 2;
            }
        }
        return ans;
    }
};
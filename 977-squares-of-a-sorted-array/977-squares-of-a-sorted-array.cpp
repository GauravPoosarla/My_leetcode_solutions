class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++)
        {
            int square = nums[i] * nums[i];
            result.push_back(square);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
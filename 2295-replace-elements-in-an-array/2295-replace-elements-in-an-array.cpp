class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for(int i=0; i<operations.size(); i++)
        {
            int num = operations[i][0];
            int num2 = operations[i][1];
            int index = mp[num];
            nums[index] = num2;
            mp[num] = -1;
            mp[num2] = index;
        }
        return nums;
    }
};
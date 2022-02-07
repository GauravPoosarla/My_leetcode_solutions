class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max = INT_MIN;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(max < mp[nums[i]])
            {
                max = mp[nums[i]];
                ans = i;
            }
        }
        return nums[ans];
    }
};
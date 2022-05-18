class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        int required_count = nums.size()/3;
        
        for(auto num: mp)
        {
            if(num.second > required_count)
            {
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};
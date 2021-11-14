class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for(int i=0; i<nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        int n = nums.size();
        int count=0;
        for(auto t: frequency)
        {
            if(t.second > n/2)
            {
                return t.first;
            }
        }
    return 0;
    }
};
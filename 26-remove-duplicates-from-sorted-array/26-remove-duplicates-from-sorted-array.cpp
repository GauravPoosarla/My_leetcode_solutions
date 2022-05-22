class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> sz;
        for(auto it: nums)
            sz.insert(it);
        
        int k = sz.size();
        int j = 0;
        for(auto it: sz)
        {
            nums[j] = it;
            j++;
        }
        return k;
    }
};
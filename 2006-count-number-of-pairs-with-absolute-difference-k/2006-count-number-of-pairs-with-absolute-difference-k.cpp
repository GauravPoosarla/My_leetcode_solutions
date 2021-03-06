class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();         
        
        unordered_map <int, int> alpha; 
        int count = 0 ; 
        for(int i = 0 ; i < n; i++) {
            count+= alpha[nums[i] - k];
            count+= alpha[nums[i] + k];
            alpha[nums[i]]++;
        }
        return count;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int n = nums.size() -1;
        int maxjump= nums[0];
        for(int i =1; i <= maxjump; i++){
            if (maxjump >= n) return true;
          maxjump = maxjump < i+nums[i] ? i+nums[i] : maxjump;
        }
        return false;
    }
};
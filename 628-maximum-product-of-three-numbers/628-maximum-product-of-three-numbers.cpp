class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp1 = nums[n-1]*nums[n-2]*nums[n-3]; // positive numbers
        int temp2 = nums[0]*nums[1]*nums[n-1]; // largest two negative nubers and biggest positive number
        
        return temp1>temp2 ? temp1:temp2;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> store;
        store = nums;
        sort(nums.begin(), nums.end());
        vector<int> result;
        int num1, num2;
        int i = 0, j = nums.size()-1;
        while(i < j)
        {
            if(nums[i] + nums[j] == target)
            {
                num1 = nums[i];
                num2 = nums[j];
                break;
            }
            else if(nums[i] + nums[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        for(int i=0; i<store.size(); i++)
        {
            if(store[i] == num1)
                result.push_back(i);
            else if(store[i] == num2)
                result.push_back(i);
        }
        return result;
    }
};
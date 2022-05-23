class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                string num1 = to_string(nums[i]);
                string num2 = to_string(nums[j]);
                
                if (num1 + num2 < num2 + num1) swap(nums[i], nums[j]);
            }
        }
        
        int count = 0;
        for (int i : nums) {
            if (i == 0) count++;
            
            string num = to_string(i);
            
            res += num;
        }
                
        return count == nums.size() ? "0" : res;
    }
};
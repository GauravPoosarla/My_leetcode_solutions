class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        
        vector<int> result;
        while(low <= high)
        {
            if(numbers[low] + numbers[high] == target)
            {
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }
            else if(numbers[low] + numbers[high] < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return result;
    }
};
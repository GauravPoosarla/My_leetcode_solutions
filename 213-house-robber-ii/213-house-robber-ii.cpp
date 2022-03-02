class Solution {
private:
    int solveTabulation(vector<int> arr, vector<int> &dp)
    {
        dp[0] = arr[0];
        int n = arr.size();
        for(int i=1; i<arr.size(); i++)
        {
            int pick = arr[i];
            if(i>1)
                pick += dp[i-2];
            int nonPick = 0 + dp[i-1];
            
            dp[i] = max(pick, nonPick);
        }
        return dp[n-1];
    }
    int solve(int index, vector<int> arr, vector<int> &dp)
    {
        // pick and non pick adjacent elements
        if(index == 0)
        {
            return arr[index];
        }
        if(index < 0)
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int pick = arr[index] + solve(index-2, arr, dp);
        int notPick = 0 + solve(index-1, arr, dp);
        
        dp[index] = max(pick, notPick);
        return dp[index];
        
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        if(n == 1)
        {
            return nums[0];
        }
        for(int i=0; i<n; i++)
        {
            // either first element or last element can be there in our final subsequence
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        
        // int ans1 = solve(temp1.size()-1, temp1, dp1);
        // int ans2 = solve(temp2.size()-1, temp2, dp2);
        
        int ans1 = solveTabulation(temp1, dp1);
        int ans2 = solveTabulation(temp2, dp2);
        return max(ans1, ans2);
    }
};
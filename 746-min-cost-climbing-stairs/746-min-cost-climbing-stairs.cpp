class Solution {
private:
    int minCostClimbingStairs(vector<int>& cost, int index, vector<int>& dp)
    {
        if(index == 0 or index == 1)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int left = minCostClimbingStairs(cost, index-1, dp) + cost[index-1];
        int right = minCostClimbingStairs(cost, index-2, dp) + cost[index-2];
        
        return dp[index] = min(left, right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        // int answer = minCostClimbingStairs(cost, cost.size(), dp);   
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
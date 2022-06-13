class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();  
        
        int prev2 = 0;
        int prev1 = 0;
        
        int ans;
        for(int i=2; i<=n; i++)
        {
            int left = prev2 + cost[i-2];
            int right = prev1 + cost[i-1];
            ans = min(left, right);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
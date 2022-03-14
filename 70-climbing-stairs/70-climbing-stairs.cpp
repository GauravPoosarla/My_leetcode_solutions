class Solution {
    int climbStairsUtil(int n, vector<int>& dp)
    {        
        if(n == 0)
        {
            return 1;
        }
        
        if(n == 1)
        {
            return 1;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
public:
    int climbStairs(int n) 
    {
          vector<int> dp(n+1, -1);
  
          dp[0]= 1;
          dp[1]= 1;

          for(int i=2; i<=n; i++){
              dp[i] = dp[i-1]+ dp[i-2];
          }
          return dp[n];
    }
};
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        string s1,s2;
        // convert array elements to string to find the longest common substring
        for(int i=0;i<nums1.size();i++)
        {
            char c=nums1[i];
            s1.push_back(c);
        }
         for(int i=0;i<nums2.size();i++)
        {
            char c=nums2[i];
            s2.push_back(c);
        }
        
		
		// code for finding longest common substring
        int m=nums1.size(),n=nums2.size(),i,j,ans=0;
        
       int dp[m+1][n+1];
        
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]= 1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                
                else
                    dp[i][j]=0;
            }
        }
        
        return ans;
        
    }
};
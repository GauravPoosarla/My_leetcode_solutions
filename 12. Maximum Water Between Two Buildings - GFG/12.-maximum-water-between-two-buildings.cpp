// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int a[], int n) { 
       int start = 0, end = n - 1, ans = 0, maxAns = 0;
       while(end - start >= 2){
           ans = min(a[start], a[end]) * (end - start - 1);
           maxAns = max(ans, maxAns);
           a[end] > a[start] ? start++ : end--;
       }
       return maxAns;
   } 
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends
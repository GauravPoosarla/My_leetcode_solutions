// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        long long int start = 0;
        long long int end = x;
        
        int ans = 0;
        while(start <= end)
        {
            long long int mid = start + (end - start)/2;
            long long int sq = mid * mid;
            if(sq == x)
                return mid;
            else if(sq < x)
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
      int is_pair(int l , int h , int *a, int k){
   while(l<h){
       if(a[l]+a[h]==k){
           return 1;
       }
       else if(a[l]+a[h]<k){
           l++;
       }
       else {
           h--;
       }

   }
   return 0;
}
bool find3Numbers(int A[], int n, int X)
{
   sort(A,A+n);
   for(int i =0 ; i<n ; i++){
       if(is_pair(i+1,n-1,A,X-A[i])){
           return 1;
       }
   }
   return 0;
}

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
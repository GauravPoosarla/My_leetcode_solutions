// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    // arr[]: input array
    // n: size of array
    // x: element to find index
    //Function to find index of element x in the array if it is present.
    int closer(int arr[],int N, int x)
    {
        int lo= 0;
    int hi= N-1;
    
    while(lo<= hi){
        int mid= lo+ (hi-lo)/2;
        
        if(arr[mid]== x)
            return mid;
        else if(mid-1> 0 && arr[mid-1]== x)
            return mid-1;
        else if(mid+1<N && arr[mid+1]== x)
            return mid+1;
        
        if(arr[mid]> x)
            hi= mid-1;
        else
            lo= mid+1;
        
    }
    
    
    return -1;
    }
};


// { Driver Code Starts.

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    Solution obj;
	    int res = obj.closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}  // } Driver Code Ends
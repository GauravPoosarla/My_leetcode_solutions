// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private:
    void subsetSums(vector<int>arr, int N, int weight, vector<int>& result, int left, int right)
    {
        if(left > right)
        {
            result.push_back(weight);
            return;
        }
        subsetSums(arr, N, weight+arr[left], result, left+1, right);
        subsetSums(arr, N, weight, result, left+1, right);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> result;
        int weight = 0;
        subsetSums(arr, N, weight, result, 0, N-1);
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
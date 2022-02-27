// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b)
    {
        return M[a][b];
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        // push all elements in the stack
        for(int i=0; i<n; i++)
        {
            s.push(i);
        }
        
        // run the loop for checking the condition
        while(s.size() != 1)
        {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        
        // check if the last element is celebrity or not
        
        bool rowCheck = false;
        int celeb = s.top();
        int zeroCount = 0;
        for(int i=0; i<n; i++)
        {
            if(M[celeb][i] == 0)
            {
                zeroCount++;
            }
        }
        
        if(zeroCount == n)
        {
            rowCheck = true;
        }
        
        bool colCheck = false;
        zeroCount = 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[i][celeb] == 1)
            {
                zeroCount++;
            }
        }
        if(zeroCount == n-1)
        {
            colCheck = true;
        }
        
        
        if(rowCheck and colCheck)
        {
            return celeb;
        }
        else
        {
            return -1;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
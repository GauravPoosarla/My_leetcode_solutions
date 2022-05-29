// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    string removeConsecutiveDuplicates(string s)
    {
        string st;
        st.push_back(s[0]);
        for (int i = 1; i < s.length(); i++){
            if (s[i] != st[st.size()-1]){
                st.push_back(s[i]);
            }
        }
        return st;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
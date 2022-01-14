// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int count[26] = {0};
        for(int i=0;i <str.size(); i++)
        {
            int index = str[i] - 'a';
            count[index]++;
        }
        int max = -1;
        char ans = 0;
        for(int i=0; i<26; i++)
        {
            if(max < count[i])
            {
                ans = i;
                max = count[i];
            }
        }
        return 'a' + ans;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends
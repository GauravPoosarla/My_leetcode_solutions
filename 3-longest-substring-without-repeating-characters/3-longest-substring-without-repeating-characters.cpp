class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int count = 0;
        set<char> sz;
        for(int r=0; r<s.size(); r++)
        {
            if(sz.find(s[r]) != sz.end())
            {
                while(l < r and sz.find(s[r]) != sz.end())
                {
                    sz.erase(s[l]);
                    l++;
                }
            }
            sz.insert(s[r]);
            count = max(count, r-l+1);
        }
       return count; 
    }
};
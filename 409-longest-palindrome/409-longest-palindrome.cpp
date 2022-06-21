class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        int count = 0;
        for(auto m : mp)
        {
            if(m.second % 2 != 0)
            {
                count++;
            }
        }
        if(count > 1)
            return s.size() - count + 1;
        
        return s.size();
    }
};
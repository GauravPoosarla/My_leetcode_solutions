class Solution {
private:
        int recursive(string& s) 
        {
            int count = 0;
            for(int i = 0; i < s.size(); ++i) 
            {
                for(int j = i; j < s.size(); ++j) 
                {
                    count += helper(s, i, j);
                }
            }
        return count;
    }

    int helper(string& s, int i, int j) {
        if (i >= j) 
            return 1;
        int smallOutput = s[i] == s[j];
        return smallOutput and helper(s, i+1, j-1);
    }
public:
    int countSubstrings(string s) {
        return recursive(s);
    }
};
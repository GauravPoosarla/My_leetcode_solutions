class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 and needle.size() == 0)
        {
            return 0;
        }
        for(int i=0; i<haystack.size(); i++)
        {
            int j;
            for(j=0; j<needle.size(); j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if(j==needle.size())
            {
                return i;
            }
        }
        return -1;
    }
};
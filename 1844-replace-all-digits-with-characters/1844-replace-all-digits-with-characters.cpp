class Solution {
public:
    char shift(char s, char t)
    {
        int shift = t -'0';
        s = s + shift;
        return s;
    }
    string replaceDigits(string s) {
        for(int i=0; i<s.size(); i++)
        {
            if(i%2 == 0)
                continue;
            char c = shift(s[i-1], s[i]);
            s[i] = c;
        }
        return s;
    }
};
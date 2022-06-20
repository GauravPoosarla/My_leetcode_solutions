class Solution {
private:
    bool isPal(string s)
    {
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string result = "";
        for(int i=0; i<s.size(); i++)
        {
            if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z') or (s[i] >= '0' and s[i] <= '9'))
                result += tolower(s[i]);
        }
        bool ans = isPal(result);
        return ans;
    }
};
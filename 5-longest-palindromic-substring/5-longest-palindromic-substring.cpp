class Solution {
public:
    string longestPalindrome(string s) {
        int palindromeStartIndex = 0, longestPalindromeLength = 1;
        int sLength = s.size();
        for(int i = 0; i< sLength; ++i) {
            int right = i, left = i-1;
            //skip same characters 
            while(s[right] == s[i]) {
                right++;
            }
            while(left >= 0 && right < sLength && s[right] == s[left]) {
                left--;
                right++;
            }
            int palindromeLength = right - left - 1;
            if(palindromeLength > longestPalindromeLength) {
                longestPalindromeLength = palindromeLength;
                palindromeStartIndex = left + 1;
            } 
        }
        return s.substr(palindromeStartIndex,longestPalindromeLength);
    }
};
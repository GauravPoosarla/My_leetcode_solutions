class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        
        string first = strs[0];
        string last = strs[strs.size()-1];
        
        for(int i=0, j=0; i<first.size(), j<last.size(); i++, j++)
        {
            if(first[i] != last[i])
            {
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};
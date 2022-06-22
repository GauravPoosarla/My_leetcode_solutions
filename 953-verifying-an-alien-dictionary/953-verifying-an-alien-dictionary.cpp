class Solution {
private:
    bool checkOrder(string& a, string& b, unordered_map<char, int>& mp)
    {
        int i = 0;
        while(i < a.size() and i < b.size())
        {
            if(mp[a[i]] != mp[b[i]])
                return mp[a[i]] < mp[b[i]];
            i++;
        }
        return a.size() <= b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i< order.size(); i++)
        {
            mp[order[i]] = i;
        }
        
        for(int i=0; i<words.size()-1; i++)
            if(!checkOrder(words[i], words[i+1], mp))
                return false;
        return true;
    }
};
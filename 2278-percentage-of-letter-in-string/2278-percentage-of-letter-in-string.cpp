class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char, int> mp;
        for(auto cha: s)
        {
            mp[cha]++;
        }
        int percentage = floor(((mp[letter]*1.0)/s.size()) * 100);
        return percentage;
    }
};
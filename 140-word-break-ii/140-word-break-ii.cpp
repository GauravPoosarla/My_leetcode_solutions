class Solution {
public:
    void backtrack(vector<string>& results, vector<string> curr, string remain, unordered_set<string>& dict) {
        if(remain.length() == 0) {
            string built;
            
            for(auto& word : curr) {
                built += word + " ";
            }
            
            results.push_back(built.substr(0, built.length() - 1));
        }
        
        for(int i = 0; i <= remain.length(); ++i) {
            string find = remain.substr(0, i);
            if(dict.find(find) != dict.end()) {
                curr.push_back(find);
                backtrack(results, curr, remain.substr(i), dict);
                curr.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		// go fast!!
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
		
        vector<string> results;
        unordered_set<string> dict;
        
        for(auto& word : wordDict) {
            dict.insert(word);
        }
        
        backtrack(results, {}, s, dict);
        
        return results;
    }
};
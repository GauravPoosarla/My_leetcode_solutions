class Solution {
private:
    void letterCombinations(string digits, string output, string *map, int index, vector<string>& result)
    {
        //base case
        if(index >= digits.size())
        {
            result.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = map[number];
        
        for(int i=0; i<value.size(); i++)
        {
            output.push_back(value[i]);
            letterCombinations(digits, output, map, index+1, result);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0)
        {
            return result;
        }
        string output = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        letterCombinations(digits, output, mapping, index, result);
        return result;
    }
};
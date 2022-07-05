class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        
        string rows[numRows];
        for(int i=0; i<numRows; i++)
        {
            rows[i] = "";
        }
        
        int currRow = 0; // current row number.
        int diff = 1; // 1 downwards, -1 upwards.
        
        for(auto ch: s)
        {
            rows[currRow] += ch;
            if(currRow == numRows-1)
                diff = -1;
            else if(currRow == 0)
                diff = 1;
            
            currRow += diff;
        }
        
        string result = "";
        for(auto row : rows)
        {
            result += row;
        }
        return result;
    }
};
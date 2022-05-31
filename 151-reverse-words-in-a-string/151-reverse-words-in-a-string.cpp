class Solution {
public:
    string reverseWords(string s)
    {
       string curr="";
        stack<string> st;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                if(curr.size()>0){
                    st.push(curr);
                }
                curr.clear();
            }
            else
            {
                curr+=s[i];
            }
        }
        if(curr.size()>0){
            st.push(curr);
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()){
                res+=" ";
            }

        }
        return res;
    }
};
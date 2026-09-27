class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string c="";
        for(auto x:s){
            if(x=='('){
                st.push(c);
                c="";
            }
            else if(x==')'){
                reverse(c.begin(),c.end());
                c=st.top()+c;
                st.pop();
            }
            else{
                c+=x;
            }
        }
        return c;
    }
};
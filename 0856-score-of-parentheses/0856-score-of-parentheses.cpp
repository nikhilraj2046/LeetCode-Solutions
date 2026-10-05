class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        vector<int>ans;
        int count=0;
        int st=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                // ans.push_back(s[i]);
                count++;
            }
            else{
                count--;
                if(s[i-1]=='('){
                    st+=pow(2,count);
                }
            }
        }
        return st;
    }
};
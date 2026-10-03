class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>ans={-1};
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ans.push_back(i);
            }
            else{
                ans.pop_back();
                if(ans.empty()) ans.push_back(i);
                else maxi=max(maxi,i-ans.back());
            }
        }
        return maxi;
    }
};
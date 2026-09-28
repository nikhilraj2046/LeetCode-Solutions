class Solution {
public:
    int maxDepth(string s) {
        // stack<string>st;
        int maxi=0;
        int cnt=0;
        for(auto x:s){
            if(x=='('){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(x==')'){
                cnt--;
            }
            else {}
        }
        return maxi;
    }
};
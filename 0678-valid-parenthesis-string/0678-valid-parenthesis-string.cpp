class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(auto x:s){
            if(x=='('){
                maxi++;
                mini++;
            }
            else if(x==')'){
                maxi--;
                mini--;
            }
            else if(x=='*'){
                maxi++;
                mini--;
            }
            if(maxi<0) return false;
            if(mini<0) mini=0;
        }  
        return mini==0; 
    }
};
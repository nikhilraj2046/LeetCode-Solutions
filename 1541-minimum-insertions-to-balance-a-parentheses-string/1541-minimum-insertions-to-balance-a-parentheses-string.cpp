class Solution {
public:
    int minInsertions(string s) {
        int count=0;
        int ans=0;
        for(auto c:s){
            if(c=='('){
                count+=2;
                if(count%2!=0){
                    ans++;
                    count--;
                }
            }
            else {          
                    count--;
                    if(count<0){
                        ans++;
                        count+=2;
                    }           
            }
        }
        return ans+count;
    }
};
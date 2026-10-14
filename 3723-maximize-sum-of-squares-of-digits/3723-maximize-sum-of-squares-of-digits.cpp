class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int x=sum/9;
        int rem=sum%9;
        string ans(x,'9');
        if(rem>0){
            ans+=char('0'+rem);

        }
        ans.append(num-ans.size(),'0');
        return ans;
    }
};
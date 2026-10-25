class Solution {
public:
    int calculateScore(int a, int b) {
        string s1=bitset<8>(a).to_string();
        string s2=bitset<8>(b).to_string();
        int cnt=0,cnt1=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='1'){
                cnt++;
            }
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='1'){
                cnt1++;
            }
        }
        if(cnt>=cnt1) return cnt*cnt1;
        return cnt1/cnt;
    }
};
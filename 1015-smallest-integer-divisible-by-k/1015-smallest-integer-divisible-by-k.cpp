class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        int rem=0;
        for(int i = 1 ;i <= k;i++){
            int newrem = (rem*10+1)%k;
            if(newrem==0) return i;
            rem=newrem;
        }
        return -1;
    }
};
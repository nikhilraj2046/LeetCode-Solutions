class Solution {
public:
    int nextNumber(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d*d;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n=nextNumber(n);
        }
        return n==1;
    }
};
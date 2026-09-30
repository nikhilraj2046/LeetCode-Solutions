class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long  sum=0,sum1=0;
        for(auto nums:source) sum+=nums;
        for(auto num:target) sum1+=num;
        return sum==sum1;
    }
};
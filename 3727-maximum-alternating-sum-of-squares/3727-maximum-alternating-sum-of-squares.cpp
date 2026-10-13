class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long  ans=0;
        int n=nums.size();
        vector<long long >a(n);
        for(int i=0;i<n;i++){
            a[i]=(long) nums[i]*nums[i];
        }
        sort(a.begin(),a.end());
        int k=nums.size()/2;
        for(int j=k;j<n;j++){
            ans+=a[j];
        }
        for(int i=0;i<k;i++){
            ans-=a[i];
        }
       
        return abs(ans);
    }
};
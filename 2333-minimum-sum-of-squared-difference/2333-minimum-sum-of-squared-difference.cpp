class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long>diff(n);
        long long mini=0;
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            mini=max(mini,diff[i]);
        }
        vector<long long>freq(mini+1,0);
        for(auto x:diff) freq[x]++;
        long long k=(long long)k1+k2;
        for(long long i=mini;k>0 && i>0 ;i--){
             if(freq[i]>0){
                long long r=min(k,freq[i]);
                freq[i]-=r;
                freq[i-1]+=r;
                k-=r;
            }
        }
        long long ans=0;
        for (long long d=0;d<=mini;d++) {
            ans+=freq[d]*d*d;
        }
        return ans;
    }
};
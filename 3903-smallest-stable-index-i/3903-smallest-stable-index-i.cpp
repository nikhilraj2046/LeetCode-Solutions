class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
           int maxi=INT_MIN;
           int mini=INT_MAX;
           for(int j=0;j<=i;j++){
            maxi=max(maxi,nums[j]);
           }
           for(int l=i;l<=n-1;l++){
            mini=min(mini,nums[l]);
           }
           if(maxi-mini<=k){
            return i;
           }
         
        }
    return -1;
    }
};
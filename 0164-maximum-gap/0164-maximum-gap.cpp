class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<2) return 0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
               int diff =nums[i+1]-nums[i];
               maxi=max(maxi,diff);
        }
        return maxi;
    }
};
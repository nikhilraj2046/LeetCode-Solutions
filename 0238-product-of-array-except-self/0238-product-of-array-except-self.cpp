class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        long p=1,p2=1,cnt=0;
        for(int i :nums){
            p*=i;
            if(i==0){
                cnt++;
                continue;
            }
            p2*=i;
        }
        int i =0;
        while(i<n){
            if(nums[i]==0 && cnt == 1){
                ans[i] = p2;
            }
            else if(nums[i] == 0 && cnt >1){
                ans[i]=0;
            }
            else{
                ans[i]=p/nums[i];
            }
            i++;
        }
        return ans;
    }
};
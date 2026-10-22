class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int asc=1,des=1,idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) {
                idx=i;
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)%n) asc++;
            if(nums[i-1]==(nums[i]+1)%n) des++;
        }
        if(asc==n){
            if(idx==0) return 0;
            return min(idx,n-idx+2);
        }
         if(des==n){ 
            return min(((idx+1)%n)+1,n-idx);
        }
        return -1;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //brute force
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int largest=INT_MIN;
            int smallest=INT_MAX;
            for(int j=i;j<n;j++){
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                sum+=largest-smallest;
            }
        }
        return sum;
    }
};
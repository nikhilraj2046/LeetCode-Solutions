class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        while(!nums.empty()){
            sort(nums.begin(),nums.end());
            vector<int>y;
            int maxi=INT_MIN;
            for(auto x:nums) {
                if(x!=maxi) {
                    ans.push_back(x);
                    maxi=x;
            }
                else{
                    y.push_back(x);
                }
        }
            nums=y;
        }
        return ans;
    }
};
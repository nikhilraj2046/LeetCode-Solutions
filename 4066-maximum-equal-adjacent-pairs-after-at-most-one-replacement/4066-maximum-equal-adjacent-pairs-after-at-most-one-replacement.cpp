class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        map<pair<int,int>,int>map;
        for(int i=1;i<n;i++){
            int prev=nums[i-1];
            int curr=nums[i];
            if(prev==curr){
                cnt++;
            }
            else{
                if(prev>curr) {
                    swap(prev,curr);
                }
                map[{prev,curr}]++;
            }
        }
        int maxi=0;
        for(auto it:map) maxi=max(maxi,it.second);
        return cnt+maxi;
    }
};
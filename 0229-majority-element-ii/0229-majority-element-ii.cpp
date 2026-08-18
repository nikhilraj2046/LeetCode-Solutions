class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_set<int> processed; 
        for(int i=0;i<n;i++){
              if(processed.count(nums[i])) continue; 
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>n/3){
                ans.push_back(nums[i]);
                processed.insert(nums[i]);
            }

        }
        return ans;
    }
};
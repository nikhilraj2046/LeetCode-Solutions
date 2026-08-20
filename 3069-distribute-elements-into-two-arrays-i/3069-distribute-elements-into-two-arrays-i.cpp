class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans1;
        vector<int>ans2;
        vector<int>fans;
            ans1.push_back(nums[0]);
            ans2.push_back(nums[1]);
        for(int i=2;i<n;i++){
                if(ans1.back()>ans2.back()){
                    ans1.push_back(nums[i]);
                }
                else{
                    ans2.push_back(nums[i]);
                }
        }
        for(int i=0;i<ans1.size();i++){
            fans.push_back(ans1[i]);
        }
        for(int i=0;i<ans2.size();i++){
            fans.push_back(ans2[i]);
        }
        return fans;

        
    }
};
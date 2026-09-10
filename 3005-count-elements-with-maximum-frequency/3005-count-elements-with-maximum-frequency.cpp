class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>c;
        int n=nums.size();
        int maxfreq=0;
        for(int i=0;i<n;i++){
            c[nums[i]]++;
            maxfreq=max(maxfreq,c[nums[i]]); 
        }
        int total=0;
            for(auto x:c){
                if(x.second==maxfreq){
                    total+=maxfreq;
                }
            }
            return total;
        

    }
};
class Solution {
public:
// using monotonic stack
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>s; 
        // vector<int>nge[nums1.size()];
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()) nge[nums2[i]]=-1;
            else 
            nge[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int x:nums1){
            ans.push_back(nge[x]);
        }
        return ans;
    }
};
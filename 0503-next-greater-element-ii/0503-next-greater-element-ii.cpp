class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);
        //using brute force
        for(int i=0;i<n;i++){
            for(int j=i+1;j<i+n;j++){
                int idx=j%n;
                if(arr[idx]>arr[i]){
                    ans[i]=arr[idx];
                    break;
                }
            }
        }
        return ans;
    }
};
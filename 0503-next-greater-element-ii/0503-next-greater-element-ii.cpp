class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        // int n=arr.size();
        // vector<int>ans(n,-1);
        // //using brute force
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<i+n;j++){
        //         int idx=j%n; // circular array
        //         if(arr[idx]>arr[i]){
        //             ans[i]=arr[idx];
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //optimised approach using monotonic stck
        int n=arr.size();
        stack<int>st;
        vector<int>nge(n,-1);
       
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i%n]){
                st.pop();
            }
            if(i<n){
                nge[i]=st.empty()?-1:st.top();
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};
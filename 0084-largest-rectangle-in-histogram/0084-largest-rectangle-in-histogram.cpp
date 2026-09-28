class Solution {
public:
      vector<int> findNSE(vector<int>& arr){
        int n=arr.size();   stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);

        }
        return nse;
    }
      vector<int> findPSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& arr) {
         vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            int area=arr[i]*(nse[i]-pse[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
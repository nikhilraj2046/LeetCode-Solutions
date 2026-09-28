class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        //using one pass solution only initiating pse
        stack<int>st;
        int n=arr.size();
        int nse=0,pse=0;
        int maxArea=0;
        int element=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea=max(arr[element]*(nse-pse-1),maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            element=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
        return maxArea;
    }
};
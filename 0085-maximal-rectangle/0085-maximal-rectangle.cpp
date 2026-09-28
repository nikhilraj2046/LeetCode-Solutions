class Solution {
    private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>prefixSum(n,vector<int>(m,0));
        int maxArea=0;
        for(int j=0;j<m;j++)
        {
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                sum+=1;
                }
                else sum=0;
                prefixSum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++) {
            maxArea=max(maxArea,largestRectangleArea(prefixSum[i]));
        }
        return maxArea;
    }
};
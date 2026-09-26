class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute force
//         int n=temperatures.size();
//          vector<int>ans(n,0);
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(temperatures[j]>temperatures[i]){
//                     ans[i]=j-i;
//                     break;
//                 }
//             }
//         }
//             return ans;
//         }
// };

//using monotonic stack
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int temp = st.top();
                st.pop();
                ans[temp] = i - temp;
            }
            st.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
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
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGE(arr);
        long long sumMax = 0;
        long long sumMin = 0;
        int n=arr.size();
        for (int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            sumMin += leftMin * rightMin * arr[i];
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            sumMax += leftMax * rightMax * arr[i];
        }
        return sumMax-sumMin;
    }
};
class Solution {
public:
    int trap(vector<int>& arr) {
        /*
        int n=height.size();
        int water=0;
        for(int j=0;j<n;j++){
            int leftMax=0,rightMax=0;
            for(int i=0;i<=j;i++){
                leftMax=max(leftMax,height[i]);
            }
            for(int r=j;r<n;r++){
                rightMax=max(rightMax,height[r]);
            }
            water+=min(leftMax,rightMax)-height[i];
        }
        return water;
        */
        /*
//USING TWO ARRAY CONCEPT
    int n = height.size();
    if (n == 0) return 0;

    vector<int> prefix(n), suffix(n);

    // Build prefix max array
    prefix[0] = height[0];
    for (int j = 1; j < n; j++)
        prefix[j] = max(prefix[j - 1], height[j]);

    // Build suffix max array
    suffix[n - 1] = height[n - 1];
    for (int j = n - 2; j >= 0; j--)
        suffix[j] = max(suffix[j + 1], height[j]);

    // Calculate trapped water
    int ans = 0;
    for (int j = 0; j < n; j++)
        ans += min(prefix[j], suffix[j]) - height[j];

    return ans;
*/
        int lmax = 0, rmax = 0;
        int n = arr.size();
        int l = 0, total = 0;
        int r = n - 1;
        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (lmax > arr[l]) {
                        total += lmax - arr[l];
                    } else {
                        lmax = arr[l];
                    }
                    l++;
                } else {
                    if (rmax > arr[r]) {
                        total += rmax - arr[r];
                    } else {
                        rmax = arr[r];
                    }
                    r--;
                }
            }
        
        return total;
    }
};
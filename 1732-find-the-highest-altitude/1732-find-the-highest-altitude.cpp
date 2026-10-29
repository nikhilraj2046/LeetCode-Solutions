class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int prefix = 0;
        for (int i = 0; i < gain.size(); i++) {
            prefix = prefix + gain[i];
            maxi = max(maxi, prefix);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int> seen;

        for (int num : nums) {
            seen.insert(num);
        }

        vector<int> ans;

        for (int i = 1; i <= n; i++) {

            if (seen.find(i) == seen.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
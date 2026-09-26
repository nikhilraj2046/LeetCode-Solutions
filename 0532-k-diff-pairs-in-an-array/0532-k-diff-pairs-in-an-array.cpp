class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        int count = 0;
        while (left < n && right < n) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else if (nums[right] - nums[left] > k) {
                left++;
            } else {
                count++;
                left++;
                while (left < n && nums[left] == nums[left - 1]) {
                    left++;
                }
            }
        }
        return count;
    }
};
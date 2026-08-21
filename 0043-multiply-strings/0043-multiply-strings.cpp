class Solution {
public:
    string multiply(string nums1, string nums2) {
        vector<int> ans(nums1.size() + nums2.size(), 0);
        if (nums1 == "0" || nums2 == "0")
            return "0";
        for (int i = nums1.size() - 1; i >= 0; i--) {
            int d1 = nums1[i] - '0';
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int d2 = nums2[j] - '0';
                int mul = d1 * d2;
                int sum = mul + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string result = "";
        int i = 0;
        while (i < ans.size() && ans[i] == 0) {
            i++;
        }
        while (i < ans.size()) {
            result.push_back(ans[i] + '0');
            i++;
        }

        return result;
    }
};
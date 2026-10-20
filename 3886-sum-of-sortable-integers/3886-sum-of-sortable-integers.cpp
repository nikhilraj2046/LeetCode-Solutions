class Solution {
public:
    vector<int> checkCyclic(int start, int end, vector<int>&nums){
        vector<int> arr(3);
        arr[0] = nums[start];
        arr[1] = nums[start];
        int n = end - start + 1;
        int falseCount = 0;
        for (int i = start; i <= end; i++) {
            if ((i < end && nums[i] > nums[i + 1]) || (i == end && nums[end] > nums[start]))
                falseCount++;
            arr[0] =min(arr[0], nums[i]);
            arr[1] =max(arr[1], nums[i]);
        }
        if (falseCount >= 2)
            arr[2] = 0;
        else 
            arr[2] = 1;
        return arr;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> div;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                div.push_back(i);
        }
        int sum = 0;
        for (int k : div) {
            bool isValid = true;
            int prevMax = -1;
            for (int i = 0; i < n; i += k) {
                vector<int> arr = checkCyclic(i, i + k - 1, nums);
                if (arr[2] == 0 || arr[0] < prevMax) {
                    isValid = false;
                    break;
                }
                prevMax = arr[1];
            }
            if (isValid)
                sum += k;
        }
        return sum;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        if (target < 0) return -1;       
        if (target == 0) return n;       

        int left = 0, currSum = 0, maxLen = -1;

        for (int right = 0; right < n; right++)
        {
            currSum = currSum + nums[right];

            while (currSum > target && left <= right)
            {
                currSum = currSum - nums[left];
                left++;
            }

            if (currSum == target)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : n - maxLen;
    }
};
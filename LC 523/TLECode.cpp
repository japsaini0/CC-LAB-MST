class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum;

        for(int i = 0; i < n; i++)
        {
            sum = nums[i];

            for(int j = i + 1; j < n; j++)
            {
                sum = sum + nums[j];

                if(sum % k == 0)
                {
                    return true;    
                }
            }
        }

        return false;   
    }
};
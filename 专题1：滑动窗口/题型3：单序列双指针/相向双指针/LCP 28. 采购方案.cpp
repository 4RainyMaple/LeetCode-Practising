class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        long long cnt = 0;
        while ( left < right )
        {
            int sum = nums[left] + nums[right];
            if ( sum <= target )
            {
                cnt += right - left;
                left++;
            }
            else
                right--;
        }
        return cnt % 1000000007;
    }
};

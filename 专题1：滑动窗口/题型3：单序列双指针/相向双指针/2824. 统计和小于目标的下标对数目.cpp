class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int left = 0;
        int right = nums.size() - 1;
        while ( left < right )
        {
            int sum = nums[left] + nums[right];
            if ( sum < target )
            {
                // 这个左闭右开区间内的组合都是合法的
                // 这里可以理解为以 left 为基准，计算每种 left 的情况下 right 的种数
                cnt += right - left;
                left++;
            }
            else
                right--;
        }
        return cnt;
    }
};

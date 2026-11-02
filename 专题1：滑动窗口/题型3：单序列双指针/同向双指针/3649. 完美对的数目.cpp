// 几何意义：
// 第二条式子是恒成立的
// 第一条式子等价于 |a|<=|b|<=2|a|

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for ( int & x : nums )
            x = abs(x);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        long long ans = 0;
        for ( int fast = 0; fast < n; fast++ )
        {
            // 大于等于之后开始都成立
            while ( 2 * nums[slow] < nums[fast] )
                slow++;
            ans += fast - slow;
        }

        return ans;
    }
};

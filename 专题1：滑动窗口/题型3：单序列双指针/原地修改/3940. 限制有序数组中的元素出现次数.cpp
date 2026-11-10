class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int minNum = nums[k];
        int score = nums[k];
        // 循环 t - 1 轮恰好两边都到尽头
        // 这样就不需要循环后又判断一次该往哪边移动
        for ( int t = 0; t < n - 1; t++ )   
        {
            // 左移条件：
            // 1.右指针到尽头了
            // 2.区间外左边比右边高，这样最小值能尽可能大，和盛水最大的容器不一样
            if ( j == n - 1 || i > 0 && nums[i - 1] >= nums[j + 1] )
                minNum = min ( minNum, nums[--i]);
            else
                minNum = min ( minNum, nums[++j]);
            score = max ( score, minNum * ( j - i + 1 ) );
        }
        return score;
    }
};

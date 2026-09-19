//贪心算法：每次取局部最优，得到整体最优
//每次都跳到“这次+下次到达最远”的地方

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int maxPos = 0; //在某个位置能调最远的距离
        int end = 0;    //表示通过step步能达到最远的位置，判断是否需要下一次step
        for ( int i = 0; i < (int)nums.size() - 1; ++i )
        {
            maxPos = max( maxPos, i + nums[i] );    //其实就是找最大的i+nums[i]换了种简洁的写法

            if ( i == end )
            {
                ++step;
                end = maxPos;
            }
        }
        return step;
    }
};

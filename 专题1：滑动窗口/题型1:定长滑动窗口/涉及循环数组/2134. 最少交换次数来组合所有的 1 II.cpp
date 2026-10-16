//转换为求解数组中0最多的窗口

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int maxNum = 0;
        int curNum = 0;
        int totalNum = 0;
        int len = (int)nums.size();
        for ( int i = 0; i < len; i++ )
            totalNum += nums[i] ? 0 : 1;

        //转化为处理滑动窗口并不困难，关键是如何处理环形数组
        //这里我们延长right的枚举长度，即加上totalNum - 1
        for ( int right = 0; right < len + totalNum - 1; right++ )
        {
            curNum += nums[right % len] ? 0 : 1;

            int left = right - totalNum + 1;
            if ( left < 0 )
                continue;

            maxNum = max ( maxNum, curNum );
            curNum -= nums[left] ? 0 : 1;   //left不会越界
        }

        return totalNum - maxNum;
    }
};

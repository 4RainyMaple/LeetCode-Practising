class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = (int) nums.size();
        //第一步：从右往左，找到第一个（否则会跳动很大）可以增大的位置。
        int declineIndex = -1;
        for ( int i = len - 1; i >= 0; --i )
        {
            if ( i < len - 1 && nums[i] < nums[i+1] )
            {
                declineIndex = i;
                break;
            }
        }
        //找不到说明数组是逆序，直接调为最小后返回即可
        if ( declineIndex == -1 )
        {
            numsReverse( nums.begin(), nums.end() -1 );
            return;
        }

        //第二步：用右侧比它大的最小（使跳动幅度最小）数字替换它。
        //由于右侧是降序，故只需从右开始找到第一个大于待交换值的项
        for ( int j = len - 1; j > declineIndex; --j )
        {
            if ( nums[j] > nums[declineIndex] )
            {
                swap ( nums[j], nums[declineIndex] );
                break;
            }
        }

        /*第三步：把右侧变成最小排列（交换后已经比原来大了，要让这个数取到最小）。
                由于右边是降序排列（参考第一步），故直接翻转即可*/
        auto left = nums.begin() + declineIndex + 1;
        auto right = nums.end() - 1;
        numsReverse( left, right );
    }

    //注意两个参数都是闭区间
    void numsReverse( vector<int>::iterator left, vector<int>::iterator right )
    {
        while ( left < right )
        {
            swap( *left, *right );
            ++left;
            --right;
        }
    }
};

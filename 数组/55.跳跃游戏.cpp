//贪心算法

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        int len = (int)nums.size();
        for ( int i = 0; i < len; ++i )
        {
            if ( i > maxPos )   //说明该位置不可达，终点更不可达，直接返回即可
                return false;   //这与上一题不同，上一题保证可达

            int distance = len - 1 - i;
            if ( distance <= nums[i] )
                return true;

            maxPos = max( maxPos, i + nums[i] );    //更新maxPos
        }
        return false;
    }
};

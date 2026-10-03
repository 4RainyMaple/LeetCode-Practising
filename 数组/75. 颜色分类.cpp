//本题使用冒泡排序可以很快完成任务而且用时很短，但是时间复杂度很高

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = (int)nums.size();
        int p = 0;

        //注意遍历需要从0开始，否则p会慢一步
        for ( int i = 0; i < len; i++ )
            if ( nums[i] == 0 )
            {
                swap( nums[p], nums[i] );
                p++;
            }

        for ( int j = p; j < len; j++ )
            if ( nums[j] == 1 )
            {
                swap( nums[p], nums[j] );
                p++;
            }
    }
};

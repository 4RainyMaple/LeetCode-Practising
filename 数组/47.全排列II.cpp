class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        recursion( nums, ret, 0 );
        return ret;
    }

    void recursion( vector<int>& nums, vector<vector<int>> &ret, int left )
    {
        int len = (int) nums.size();   

        if ( left == len - 1 )
        {
            ret.push_back(nums);
            return;
        }

        bool used [21] = {false};
        for ( int i = left; i < len; ++i )
        {
            /*这题跟上一题的区别就在于去重
               不止要去掉与开头相同的值
               已经交换过的值也要去掉*/
            if ( used[ nums[i] + 10 ] )     //[-10,10]负值会越界，把每个值后移10即可
                continue;

            used[ nums[i] + 10 ] = true;
            swap( nums[i], nums[left] );
            recursion( nums, ret, left + 1 );
            swap( nums[i], nums[left] );
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret; 
        recursion( nums, 0, ret );
        return ret;
    }

    void recursion( vector<int>& nums, int left, vector<vector<int>> &ret ) //闭区间
    {
        
        int len = (int) nums.size();

        if ( left == len - 1 )
            ret.push_back(nums);    //这时nums已经交换完成，直接装进容器即可
        
        for ( int i = left; i < len; ++i )  //注意自己和自己交换也要算进去
        {
            swap( nums[left], nums[i] );          
            recursion( nums, left + 1, ret );
            swap( nums[left], nums[i] );    //记得要换回来，否则下一次交换就乱了
        }
    }
};

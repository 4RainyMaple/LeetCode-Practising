class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        size_t sum = 0;
        size_t product = 1;

        // sum 初始化最后一个元素不能算进去
        for ( int i = 0; i < nums.size() - 1; i++ )
            sum += nums[i];
        for ( int j = nums.size() - 1; j > 0; j-- )
        {
            // 上来先判断
            if ( sum == product )
                return j;
            // 更新左边的和
            sum -= nums[j - 1];
            // 预判，防溢出
            if ( product > sum / nums[j] )
                break;
            // 更新右边积
            product *= nums[j];
        }
        return -1;
    }
};

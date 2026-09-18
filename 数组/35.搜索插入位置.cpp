class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = (int) nums.size();

        //等价于找第一个>=target的元素，即lower_bound的实现思路
        int left = 0 , right = len - 1;
        int mid;
        while ( left <= right )
        {
            mid = ( left + right ) / 2;

            if ( nums[mid] < target )
                left = mid + 1;

            else 
                //mid左边可能还有符合条件的元素，往左筛查
                right = mid - 1;
        }

        /*
            left 左边的元素都小于 target
            right 右边的元素都大于等于 target
            循环结束时left = right + 1
            故left即为所求
        */
        return left;
    }
};

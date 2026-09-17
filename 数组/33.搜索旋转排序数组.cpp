//O(logN)考虑二分查找

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int len = (int) nums.size();

        //先处理空数组
        if ( nums.empty() )
            return -1;

        //只有一个元素不需要二分查找
        if ( len == 1 )
            return nums[0] == target ? 0 : -1;
        
        int left = 0;
        int right = len - 1;
        int mid;
        //将数组均分为两半，至少有一半是有序的
        while ( left <= right )
        {
            mid = ( left + right ) / 2;
            if ( nums[mid] == target )
                return mid;

            //注意：必须先判断是否有序，才能判断target是否在该区间内
            //若左半有序
            if ( nums[0] <= nums[mid] )
            /*关于为什么要取等：
            nums = [3,1], target = 1
            left = 0，right = 1，mid = 0
            使用 <= 时：
            - 3 <= 3 成立，进入左半有序的分支。
            - target 不在 [3,3) 中，因此令 left = mid + 1 = 1。
            - 下一轮找到 1，返回下标 1。
            如果改成 <：
            - 3 < 3 不成立，错误地进入右半有序的分支。
            - 但此时 [3,1] 实际上并不有序。
            - nums[mid] < target，即 3 < 1，不成立，于是令 right = mid - 1 = -1。
            - 循环结束，错误地返回 -1。*/
            {
                //判断target是否在左区间，开始折半区间
                if ( nums[0] <= target && target < nums[mid] )
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            //右半有序
            else 
            {
                //判断target是否在右区间，开始折半区间
                if ( nums[mid] < target && target <= nums[len-1] )
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

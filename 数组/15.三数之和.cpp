/*
我们先从三重循环入手（尽管这肯定不是最好的算法）
不重复意味着第二重循环的数与第一重不同，第三重循环的数与第二重循环不同
如果每次都走一轮太麻烦了，最好的办法就是先排序（O(NlogN)），如此数组是不减的
排序好后再循环，只要发现枚举的数字与上一个相同就直接往下走

在第一重循环内，注意到如果第二个数增加，那第三个数就要减小
这种情况下可以考虑双指针法，把后两重循环合并为一重循环
记第二个下标为left,第三个数下标为right
让left循环枚举，每次right从最右端往左走，只要三数之和为0就停止，进入下一个循环
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        sort( nums.begin(), nums.end() );
        int len = (int)nums.size();
      
        for ( int i = 0; i < len; ++i )
        {
            if ( i > 0 && nums[i] == nums[i-1] )  //注意别上来就查重，会越界访问
                continue;
            
            int right = len - 1;
            for ( int left = i + 1; left < len; ++left )
            {
                if ( left > i + 1 && nums[left] == nums[left-1] )
                    continue;
              
                while ( left < right && nums[i] + nums[left] + nums[right] > 0 )
                {
                    --right;
                }
                if ( left == right )  //别让这两交错，否则重复
                    break;
              
                if ( nums[i] + nums[left] + nums[right] == 0 )
                    ret.push_back({nums[i],nums[left],nums[right]});
            }
        }
        return ret;
    }
};

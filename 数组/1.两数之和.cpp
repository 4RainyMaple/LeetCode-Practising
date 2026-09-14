//哈希表的算法待补充
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for ( int i = 0; i < nums.size(); ++i )
          //注意这里返回值是int，所以i和j直接定义为int
        {
            for ( int j = i + 1; j < nums.size(); ++j )
            {
                if ( nums[i] + nums[j] == target )
                {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

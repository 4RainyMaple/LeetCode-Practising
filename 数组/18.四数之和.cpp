//双指针神了
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        //经典排序起手
        sort( nums.begin(), nums.end() );
        int len = (int) nums.size();
        long long sum;
        vector<vector<int>> ret;

        for ( int i = 0; i < len - 3; ++i )
        {
            //如果本轮最小的都比target大，那后面的更不用看
            if ( (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target )
                break;
            //如果本轮最大的都比target小，那直接进入下一轮
            if ( (long long)nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target )
                continue;
            if ( i > 0 && nums[i] == nums[i-1] )
                continue;

            for ( int j = i + 1; j < len - 2; ++j )
            {
                if ( j > i + 1 && nums[j] == nums[j-1] )
                    continue;

                int left = j + 1;
                int right = len - 1;

                while ( left < right )
                {
                    //为防止溢出，要让第一个元素直接转换类型，后面自动跟着
                    sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if ( sum == target )
                    {
                        ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        //不要直接break后面可能还有符合的
                        ++left;
                        //查重
                        while ( left < right && nums[left] == nums[left-1] )
                            ++left;
                    }

                    else if ( sum > target )
                    {
                        --right;
                        while( left < right && nums[right] == nums[right+1] )
                            --right;
                    }
                    
                    else
                    {
                        ++left;
                        while ( left < right && nums[left] == nums[left-1] )
                            ++left;
                    }
                }
            }
        }
        return ret;
    }
};

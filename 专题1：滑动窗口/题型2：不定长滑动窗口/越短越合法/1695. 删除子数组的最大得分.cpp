class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int,bool> exist;
        int curSum = 0;
        int maxSum = 0;
        int left = 0;
        for( int right = 0; right < n; right++ )
        {
            curSum += nums[right];
            //若之前未存在就标记为存在
            if( !exist[nums[right]] )
                exist[nums[right]] = true;
            //若之前存在就让左窗口不断右移，直到把之前存在的相同元素删掉
            else
            {
                while( nums[left] != nums[right] )
                {
                    exist[nums[left]] = false;
                    curSum -= nums[left++];
                }
                curSum -= nums[left++];
            }
            maxSum = max( maxSum, curSum );
        }
        return maxSum;
    }
};

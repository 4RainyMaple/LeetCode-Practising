class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long curSum = 0;
        long long maxSum = 0;
        unordered_map<int,int> cnt;     //记录元素出现次数的哈希表
        cnt.reserve(k);                 //提前预留空间，以免反复扩容浪费时间
        for ( int right = 0; right < nums.size(); right++ )
        {
            curSum += nums[right];
            cnt[nums[right]]++;

            int left = right - k + 1;
            if ( left < 0 )
                continue;
            
            if ( cnt.size() >= m )
                maxSum = max( maxSum, curSum );

            curSum -= nums[left];
            if ( --cnt[nums[left]] == 0 )   //次数为0的元素直接删除
                cnt.erase(nums[left]);
        }
        return maxSum;
    }
};

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //直接对数组做初始化全为 -1，然后替换其中元素即可
        vector<int> ans(nums.size(),-1);
        //注意类型
        long long curSum = 0;   
        //不用搞那么复杂，其实就是[right - 2k - 1,right]的定长滑动窗口，注意中间还有一个元素
        for ( int right = 0; right < nums.size(); right++ )
        {
            curSum += nums[right];
            int left = right - 2*k;
            if ( left < 0 )
                continue;
            ans[right - k] = curSum / (2*k + 1);
            curSum -= nums[left];
        }
        return ans;
    }
};

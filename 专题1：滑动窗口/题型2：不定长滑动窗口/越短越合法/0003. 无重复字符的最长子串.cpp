class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> cnt;
        int n = (int)s.size();
        int ans = 0;
        int left = 0;
        for ( int right = 0; right < n; right++ )
        {
            ++cnt[s[right]] ;
            //只要发现重复元素左端点就一直右移
            while ( cnt[s[right]] > 1 )
            {
                //由于我们确保每次进来的滑动窗口都是无重复的，故只需针对新进来的元素进行缩减窗口
                cnt[s[left]]--;
                left++;
            }
            //一定要确保没有重复元素才能更新答案
            ans = max( ans, right - left + 1 );
        }
        return ans;
    }
};

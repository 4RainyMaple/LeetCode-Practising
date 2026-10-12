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
            while ( cnt[s[right]] > 1 )
            {
                cnt[s[left]]--;
                left++;
            }
            ans = max( ans, right - left + 1 );
        }
        return ans;
    }
};

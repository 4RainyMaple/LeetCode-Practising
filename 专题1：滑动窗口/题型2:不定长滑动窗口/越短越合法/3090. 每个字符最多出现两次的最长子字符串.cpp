class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> cnt(26);
        int n = (int)s.size();
        int left = 0;
        int ans = 0;
        for ( int right = 0; right < n; right++ )
        {
            ++cnt[s[right]];
            while( cnt[s[right]] > 2 )
            {
                cnt[s[left]]--;
                left++;
            }
            ans = max ( ans, right - left + 1 );
        }
        return ans;
    }
};

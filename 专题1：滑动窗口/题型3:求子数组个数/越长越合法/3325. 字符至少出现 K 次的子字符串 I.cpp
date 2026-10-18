class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int left = 0;
        int num = 0;
        unordered_map<char,int> cnt(26);
        for ( int right = 0; right < (int)s.size(); right++ )
        {
            ++cnt[s[right]];
            // 由于每轮循环结束后窗口中都是没有元素数量达到 k 的
            // 要是出现哪个元素数量达到 k 的那肯定是新加进来的
            while ( cnt[s[right]] >= k ) 
                --cnt[s[left++]];

            ans += left;
        }
        return ans;
    }
};

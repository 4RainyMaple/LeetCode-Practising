class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> cnt;
        int left = 0;
        int ans = 0;
        for ( int right = 0; right < (int)s.size(); right++ )
        {
            cnt[s[right]]++;
            while ( cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0 )
                --cnt[s[left++]];
            //下标为 left 处开始不满足，说明前面 left 个位置是满足的
            ans += left;
        }
        return ans;
    }
};

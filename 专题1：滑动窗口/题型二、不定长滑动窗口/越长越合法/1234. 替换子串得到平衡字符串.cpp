class Solution {
public:
    int balancedString(string s) {
        int n = (int)s.size();
        int m = n / 4;
        int ans = INT_MAX;
        int left = 0;

        //若子串外面的四种字母数量均小于 m，则可以通过替换子串内字母来达到平衡
        //注意：子串本身是什么并不重要，因为可以任意替换，只关心子串长度
        unordered_map<char,int> cnt;    //统计子串外各字母的数量
        for ( const char & c : s )
            cnt[c]++;

        //原字符串已经平衡，直接返回
        if ( cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m )
            return 0;

        for ( int right = 0; right < n; right++ )
        {
            cnt[s[right]]--;

            while( cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m )
            {
                ans = min( ans, right - left + 1 );
                cnt[s[left++]]++;
            }
        }
        return ans;
    }
};

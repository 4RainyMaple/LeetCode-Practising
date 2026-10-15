class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        //先查找总数，若 s 中1的数量不足直接返回空串
        if ( ranges::count(s, '1') < k )
            return "";

        string ans;
        int len = INT_MAX;
        int left = 0;
        int cnt = 0;
        int n = (int)s.size();
        //先维护 len 这个变量，当 len 有新的最小值时更新 ans
        for ( int right = 0; right < n; right++ )
        {
            if ( s[right] == '1' )
                cnt++;
            
            while ( s[left] == '0' || cnt > k )
            {
                if ( s[left] == '1' )
                    cnt--;
                left++;
            }

            if ( cnt == k )
            {
                //注意：长度相等时要取字典序最小者
                if ( right - left + 1 < len || ( right - left + 1 == len && s.substr(left, len) < ans))
                {
                    len = right - left + 1 ;
                    ans = s.substr(left, len);
                }
                if ( len == k )
                    return ans;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countRotations(string s, int k) {
        int same = 0;
        int ans = 0;
        int n = (int)s.size();
        //最后一个left = n - 1，因此最后一个right = left + ( n -1 ) - 1
        for ( int right = 0; right <= 2 * n - 3; right++ )
        {
            if ( s[right % n] == s[(right + 1) % n] )
                same++;

            //注意窗口长度为 n - 1
            int left = right - ( n - 1 ) + 1;
            if ( left < 0 )
                continue;
            
            if ( same == k )
                ans++;

            //最后一个 left  + 1 会越界
            if ( s[left] == s[(left + 1) % n] )
                same--;
        }
        return ans;
    }
};

//我们关心的只是删去这段区间后偏移量，至于原本会到哪不重要
//因此直接计算这段区间的移动的坐标即可

class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_set<long long> points;
        int x = 0;
        int y = 0;
        for ( int right = 0; right < (int)s.size(); right++ )
        {
            switch(s[right])
            {
                case 'U': y++;  break;
                case 'D': y--;  break;
                case 'L': x--;  break;
                case 'R': x++;  break;
            }

            int left = right - k + 1;
            if ( left < 0 )
                continue;

            //这里有个很巧妙的省空间的方法：把两个数转移到一个数的不同位
            //+k是避免负数出现导致串位，注意数据量需要long long
            long long key = (long long)( x + k ) * ( 2 * k + 1 ) + ( y + k );   
            points.insert(key);

            switch(s[left])
            {
                case 'U': y--;  break;
                case 'D': y++;  break;
                case 'L': x++;  break;
                case 'R': x--;  break;
            }
        }
        return (int)points.size();
    }
};

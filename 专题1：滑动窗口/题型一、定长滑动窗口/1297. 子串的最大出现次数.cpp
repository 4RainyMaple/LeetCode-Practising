//本题只需考虑长度为minSize的子串
//假设有x个长度大于minSize的子串，则必然有至少x个长度为minSize的子串

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> str_cnt;  //记录不同子串出现的次数
        int maxCnt = 0;
        int kinds = 0;
        vector<int> let_cnt(26, 0);         //把字母出现次数放到哈希表中

        for ( int right = 0; right < s.size(); right++ )
        {
            //若字母未出现过就增加种数
            if ( let_cnt[s[right] - 'a']++ == 0 )
                kinds++;

            int left = right - minSize + 1;
            if ( left < 0 )
                continue;
            
            //字母种数符合要求才更新答案
            if ( kinds <= maxLetters )
            {
                int & cnt = ++str_cnt[s.substr(left, minSize)];
                maxCnt = max ( cnt, maxCnt );
            }
            //若字母离开后数量为0则种数减小
            if ( --let_cnt[s[left] - 'a'] == 0 )
                kinds--;
        }
        return maxCnt;
    }
};

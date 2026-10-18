class Solution {
public:
    int countVowelSubstrings(string word) {
        // 这个题比较特殊的地方是遇到辅音需要更新字串起点
        int ans = 0, start = 0, left = 0;
        unordered_map<char,int> cnt(5);
        for ( int right = 0; right < word.size(); right++ )
        {
            if ( !isVowel(word[right]) )
            {
                cnt.clear();
                start = left = right + 1;
                continue;
            }

            cnt[word[right]]++;
            while ( cnt.size() == 5 )
            {
                if ( --cnt[word[left]] == 0 ) 
                    cnt.erase(word[left]);
                left++;
            }
            ans += left - start;
        }

        return ans;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

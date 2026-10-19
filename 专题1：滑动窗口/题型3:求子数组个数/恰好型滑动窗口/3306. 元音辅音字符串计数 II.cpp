class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }

    long long solve(string & word, int k)
    {
        int left = 0, cntConsonant = 0;
        long long ans = 0;
        unordered_map<char,int> cntVowel;

        for ( int right = 0; right < word.size(); right++ )
        {
            if ( isVowel(word[right]) )
                cntVowel[word[right]]++;
            else
                cntConsonant++;
            while ( cntVowel.size() == 5 && cntConsonant >= k )
            {
                if ( isVowel(word[left]) )
                {
                    if ( --cntVowel[word[left]] == 0 )
                        cntVowel.erase(word[left]);
                }
                else
                    --cntConsonant;
                left++;
            }

            // 上一轮符合的情况，这一轮无论加进来什么东西都是满足的
            ans += left;
        }
        return ans;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

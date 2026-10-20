class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto itr = find(word.begin(), word.end(), ch);
        if ( itr == word.end() )
            return word;
        int left = 0;
        int right = itr - word.begin();
        while ( left < right )
        {
            swap(word[left], word[right]);
            left++;
            right--;
        }
        return word;
    }
};

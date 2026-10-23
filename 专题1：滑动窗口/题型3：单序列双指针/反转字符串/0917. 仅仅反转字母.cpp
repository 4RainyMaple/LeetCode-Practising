class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while ( left < right )
        {
            while ( left < right && !isLetter(s[left]) )
                left++;
            while ( left < right && !isLetter(s[right]) )
                right--;
            swap( s[left], s[right] );
            left++;
            right--;
        }
        return s;
    }

    bool isLetter(char c)
    {
        int num = (int)c;
        return (65 <= num && num <= 90) || (97 <= num && num <= 122);
    }
};

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while ( left < right )
        {
            if ( s[left] - s[right] < 0 )
                s[right] = s[left];
            else
                s[left] = s[right];
            left++;
            right--;
        }
        return s;
    }
};

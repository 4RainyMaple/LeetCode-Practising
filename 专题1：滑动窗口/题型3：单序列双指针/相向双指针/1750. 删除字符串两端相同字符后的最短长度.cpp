class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        while ( left < right )
        {
            if ( s[left] != s[right] )
                break;
            while ( left < right && s[left + 1] == s[left] )
                left++;
            while ( left < right && s[right - 1] == s[right] )
                right--;
            left++;
            right--;
        }
        return max(right - left + 1, 0);
    }
};

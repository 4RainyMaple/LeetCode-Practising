class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while ( left < right )
        {
            while ( left < right && !isLetter(s[left]) )
                left++;
            while ( left < right && !isLetter(s[right]) )
                right--;
            if ( !isSameLetter( s[left], s[right] ) )
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool isSameLetter(char c1, char c2)
    {
        if ( !isCapitalLetter(c1) && isCapitalLetter(c2) )
            return c1 - 'a' == c2 - 'A';
        else if ( isCapitalLetter(c1) && !isCapitalLetter(c2) )
            return c1 - 'A' == c2 - 'a';
        else
            return c1 == c2;
    }

    bool isCapitalLetter(char c)
    {
        return 'A' <= c && c <= 'Z';
    }

    bool isLetter(char c)
    {
        return ( 'a' <= c && c <= 'z' ) || ( 'A' <= c && c <= 'Z' ) 
            || ( '0' <= c && c <= '9' );
    }
};

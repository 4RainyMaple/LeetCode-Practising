class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = (int)answerKey.size();
        int left = 0;
        int ans = 0;
        int numT = 0;
        int numF = 0;
        for ( int right = 0; right < n; right++ )
        {
            if ( answerKey[right] == 'T' )
                numT++;
            else
                numF++;

            //关键点：改掉少数者
            while ( min(numT,numF) > k )
            {
                if ( answerKey[left] == 'T' )
                    numT--;
                else
                    numF--;
                left++;
            }

            ans = max ( ans, right - left + 1 );
        }
        return ans;
    }
};

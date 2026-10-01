class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int len = (int)digits.size();
        //处理正常情况
        for ( int i = len - 1 ; i >= 0 ; i-- )
        {
            digits[i] += carry;
            if ( digits[i] == 10 )
            {
                digits[i] = 0;
                carry = 1;
            }
            else 
                carry = 0;
        }
        //处理全为9的情况
        if ( carry == 1 )
        {
            vector<int> ans;
            ans.push_back(1);
            for ( int i = 0; i < len; i++ )
                ans.push_back(0);
            return ans;
        }
        return digits;
    }
};

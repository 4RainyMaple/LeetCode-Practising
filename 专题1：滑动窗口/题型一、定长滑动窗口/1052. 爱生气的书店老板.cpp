class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //这个问题拆分成两个部分：本来就满意的顾客 + 老板控制情绪后满意的顾客
        //先计算原本就满意的顾客，直接求和即可
        int initSum = 0;
        int time = (int)customers.size();
        for ( int i = 0; i < time; i++ )
            if ( !grumpy[i] )
                initSum += customers[i];
        //计算控制情绪后满意的顾客，定长滑动窗口可解
        int curSum = 0;
        int maxSum = 0;
        for ( int right = 0; right < time; right++ )
        {
            if ( grumpy[right] )
            curSum += customers[right];
            int left = right - minutes + 1;
            if ( left < 0 )
                continue;
            maxSum = max( maxSum, curSum );
            if ( grumpy[left] )
                curSum -= customers[left];
        }
        return initSum + maxSum;
    }
};

/*
若 k = 1，则可以合并 2 个空余时间段
若 k = 2，则可以合并 3 个空余时间段
因此，总共可以合并 k + 1 个空余时间段
这样我们就将其转换为定长滑动窗口的问题
*/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        //先构建好空余时间的集合
        int num = (int)startTime.size();
        vector<int> freeTime(num + 1);
        freeTime[0] = startTime[0];
        for ( int i = 1; i < num; i++ )
            freeTime[i] = startTime[i] - endTime[i - 1];
        freeTime[num] = eventTime - endTime[num - 1];
        //滑动窗口：注意窗口长度是 k + 1
        int maxSum = 0;
        int curSum = 0;
        for ( int right = 0; right <= num; right++ )
        {
            curSum += freeTime[right];
            int left = right - k;
            if ( left < 0 )
                continue;
            maxSum = max( maxSum, curSum );
            curSum -= freeTime[left];
        }
        return maxSum;
    }
};

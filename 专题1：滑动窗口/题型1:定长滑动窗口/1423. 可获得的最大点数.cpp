class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //正难则反：先计算总点数和，再减去最小点数和
        int totalSum = 0;
        for ( auto const & point : cardPoints )
            totalSum += point;
        //如果要拿走全部牌就直接返回
        if ( k == cardPoints.size() )
            return totalSum;

        //计算最小点数和
        int n = (int)cardPoints.size() - k;
        int curSum = 0;
        int minSum = INT_MAX;   //注意一开始最小和要赋值无穷大
        for ( int right = 0; right < (int)cardPoints.size(); right++ )
        {
            curSum += cardPoints[right];
            int left = right - n + 1;
            if ( left < 0 )
                continue;
            minSum = min( minSum, curSum );
            curSum -= cardPoints[left];
        }

        return totalSum - minSum;
    }
};

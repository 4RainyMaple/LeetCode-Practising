class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = (int)code.size();
        vector<int> ans(n);
        if ( k == 0 )
            return ans;

        //若 k > 0，则第一个窗口为[1,k+1)（0后面|k|个元素）
        //若 k < 0，则第一个窗口为[n+k,n)（0前面|k|个元素）

        //计算第一个窗口的右开端点
        int right = k > 0 ? k + 1 : n;
        k = abs(k);     //取k的绝对值，方便表示区间长度

        //计算第一个窗口和
        int sum = 0;
        for ( int i = right - k; i < right; i++ )
            sum += code[i];

        //开始滑动区间计算和，注意同时移动j和right
        for ( int j = 0; j < n; j++, right++ )
        {
            ans[j] = sum;
            sum += code[right % n] - code[(right - k) % n];
        }
        return ans;
    }
};

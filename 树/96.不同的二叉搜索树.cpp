/*
    原理：
    设G(n)为n个整数可构成二叉搜索树的种数，F(n,i)为以i为根可构成二叉搜索树的种数
    则G(n)= ∑ F(i,n)
    而F(i,n) = G(i-1) * G(n-i)   (左右种数之积)
    故G(n) = ∑ G(i-1) * G(n-i)
*/

class Solution {
public:
    int numTrees(int n) {
        // -1 表示这个节点数量对应的答案还没计算过，记忆化搜索提速
        vector<int> memo(n + 1, -1);
        return countTrees(n, memo);
    }

private:
    int countTrees(int n, vector<int>& memo) {
        // 空树有一种方案；一个节点也只有一种方案
        if (n <= 1)
            return 1;

        // 已经算过，直接使用结果
        if (memo[n] != -1)
            return memo[n];

        int total = 0;

        // 依次选择每个数字作为根节点
        for (int i = 1; i <= n; ++i) 
            total += countTrees(i - 1, memo) * countTrees(n - i, memo);

        memo[n] = total;
        return total;
    }
};

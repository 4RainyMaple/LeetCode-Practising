class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if ( n == 0 )
            return {};

        return generateTrees(1,n);
    }

private:
    vector<TreeNode*> generateTrees( int start, int end ){
        //基准情形：返回空数组
        if ( start > end )
            return {nullptr};

        vector <TreeNode*> allTrees;
        for ( int i = start; i <= end; ++i )
        {
            vector<TreeNode*> leftTrees = generateTrees( start, i - 1 );
            vector<TreeNode*> rightTrees = generateTrees( i + 1, end );
            //把所有子树放到当前树两边
            for ( auto & left : leftTrees )
            {
                for ( auto & right : rightTrees )
                {
                    TreeNode * currTree = new TreeNode(i);  //默认左右儿子指针均为nullptr
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.push_back(currTree);
                }
            }
        }
        return allTrees;
    }
};

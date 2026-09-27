class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        //为了使第一个节点能通过，将最大最小都拉满
        return isValidBST( root, LONG_MAX, LONG_MIN );
    }

private:
    bool isValidBST( TreeNode * root, long long upper, long long lower )
    {
        if ( root == nullptr )
            return true;

        //注意：不能值比较当前节点与其孩子，必须比较整棵树中的最大最小值
        if ( root->val >= upper || root->val <= lower )
            return false;

        //跟左边比不需要更新下限，跟右边比不需要更新上限
        return isValidBST( root->left, root->val, lower ) && isValidBST( root->right, upper, root->val );
    }
};

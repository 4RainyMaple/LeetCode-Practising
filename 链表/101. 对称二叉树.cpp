class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric( root->left, root->right );
    }

    bool isSymmetric(TreeNode * left, TreeNode * right)
    {
        if ( !left && !right )
            return true;
        if ( (!left && right) || (left && !right) )
            return false;
        bool flag1 = left->val == right->val;
        bool flag2 = isSymmetric( left->left, right->right );
        bool flag3 = isSymmetric( left->right, right->left );
        return flag1 &&flag2 && flag3;
    }
};

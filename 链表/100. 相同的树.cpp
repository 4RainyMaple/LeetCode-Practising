class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( !p && !q)
            return true;
        if ( (p && !q) || (q && !p) )
            return false;

        bool flag1 = isSameTree( p->left, q->left );
        bool flag2 = p->val == q->val;
        bool flag3 = isSameTree( p->right, q->right );

        return flag1 && flag2 && flag3;
    }
};

//这里的单链表其实就是只有右子树的树，那只需考虑不断把左子树搬到根的右边
class Solution {
public:
    void flatten(TreeNode* root) {
        if ( root == nullptr )
            return;

        //先保存好右子树
        TreeNode * rightChild = root->right;

        //把左子树搬到右子树的位置，清除左子树
        root->right = root->left;
        root->left = nullptr;

        //找到新的右子树最下方，把原来的右子树接上去
        TreeNode * cur = root;
        while ( cur->right != nullptr )
            cur = cur->right;
        cur->right = rightChild;
        
        //继续搬运左子树
        flatten(root->right);
    }
};

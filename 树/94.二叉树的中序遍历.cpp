/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ret;
        printTree(root, ret);
        return ret;
    }

    void printTree( TreeNode * t, vector <int> & ret )
    {
        if ( t == nullptr )
            return;
        printTree(t->left, ret);
        ret.push_back( t->val );
        printTree(t->right, ret);
    }
};

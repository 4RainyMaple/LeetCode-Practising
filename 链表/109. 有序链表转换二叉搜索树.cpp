class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getlen(head);
        return buildTree( head, 0, len - 1 );
    }

private:
    int getlen ( ListNode * head )
    {
        int len = 0;
        while ( head != nullptr )
        {
            head = head->next;
            len++;
        }
        return len;
    }

    TreeNode * buildTree ( ListNode *& head, int left, int right )
    {
        //若区间为空，则返回空指针
        if ( left > right )
            return nullptr;

        //取中位数，使树平衡
        int mid = ( left + right ) / 2;
        TreeNode * root = new TreeNode();
        //构建左子树
        root->left = buildTree( head, left, mid - 1 );
        //每次调用函数都会推进一次head，左子树构建完成后，head恰好到根的位置
        root->val = head->val;
        head = head->next;  //把根的值确定后，推进head
        //构建右子树
        root->right = buildTree( head, mid + 1, right );
        return root;
    }
};

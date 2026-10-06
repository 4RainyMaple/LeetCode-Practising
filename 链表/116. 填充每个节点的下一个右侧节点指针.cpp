class Solution {
public:
    Node* connect(Node* root) {
        if ( !root )
            return nullptr;

        Node * firstChild = root;
        
        //从每一层的大儿子开始遍历
        while ( firstChild )
        {
            Node * child = firstChild;
            while ( child )
            {
                if ( child->left )
                    child->left->next = child->right;

                if ( child->right && child->next )
                    child->right->next = child->next->left;
                //把这一层的兄弟遍历完
                child = child->next;
            }
            //前往下一层
            firstChild = firstChild->left;  
        }

        return root;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if ( head == nullptr )
            return head;
        //用来装<x的节点
        ListNode * head1 = nullptr;
        ListNode * tail1 = nullptr;
        //用来装>=x的节点
        ListNode * head2 = nullptr;
        ListNode * tail2 = nullptr;
        while ( head != nullptr )
        {
            int ele = head->val;
            if ( ele < x )
                pushNode( head1, tail1, ele );
            else
                pushNode( head2, tail2, ele );

            head = head->next;
        }
        if ( head1 != nullptr )
        {
            tail1->next = head2;
            return head1;
        }
        else
            return head2;
    }

private:
    void pushNode( ListNode *& head, ListNode *& tail , int ele )
    {
        if( head == nullptr )
            head = tail = new ListNode( ele, nullptr );
        else 
        {
            tail->next = new ListNode ( ele, nullptr );
            tail = tail->next;
        }
    }
};

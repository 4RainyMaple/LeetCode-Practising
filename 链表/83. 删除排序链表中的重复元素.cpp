//一种不太好的做法，没有直接修改原链表，但比较好想

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * lead = nullptr;
        ListNode * tail = nullptr;
        int ele = 101;
        while ( head != nullptr )
        {
            if ( ele != head->val )
                if ( lead == nullptr )
                    lead = tail = new ListNode(head->val);
                else
                {
                    tail->next = new ListNode(head->val);
                    tail = tail->next;
                }

            ele = head->val;
            head = head->next;
        }
        return lead;
    }
};

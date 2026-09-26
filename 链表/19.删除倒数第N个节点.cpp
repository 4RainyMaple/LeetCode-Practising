class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0,head);    //虚构的头节点的前一个节点
        int len = getLength(head);

        ListNode * thisNode = dummy;    //从dummy开始，才能处理删除头节点的问题
        for ( int i = 1; i <= len - n; i++ )
            thisNode = thisNode->next;

        thisNode->next = thisNode->next->next;
        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }

private:
    int getLength(ListNode* head)
    {
        int len = 1;

        while ( head->next != nullptr )
        {
            head = head->next;
            len++;
        }
        return len;
    }
};

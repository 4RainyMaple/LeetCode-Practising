class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( k == 0 || head == nullptr || head->next == nullptr )
            return head;

        //先计算链表的长度
        int len = 1;
        ListNode * cur = head;
        while ( cur->next != nullptr )
        {
            len++;
            cur = cur->next;
        }
 
        int count = len - k % len;  //注意：需要逆时针旋转，但只能做到顺时针旋转
        if ( count == len )
            return head;

        //把链表环化
        cur->next = head;
        while ( count > 0 )
        {
            count--;
            cur = cur->next;
        }
        ListNode* ans = cur->next;
        cur->next = nullptr;    //把环断开
        return ans;
    }
};

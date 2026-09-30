/*
维持三个指针：
pre指向翻转序列前的节点，cur指向待翻转的节点，next永远指向cur的下一个节点。

操作步骤：
执行操作 1：把 cur 的下一个节点指向 next 的下一个节点；
执行操作 2：把 next 的下一个节点指向 pre 的下一个节点（注意pre->next是变化的，只有一开始是cur）；
执行操作 3：把 pre 的下一个节点指向 next。

操作前：pre->cur->next->node
操作后：pre->next->cur->node
操作前：pre->next->cur->next`
操作后：pre->next`->next->cur
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //有可能操作到头结点，定义哑节点
        ListNode * dummy = new ListNode ( 0, head );
        ListNode * pre = dummy;

        //先将pre移动到待翻转序列之前
        for ( int i = 1; i < left; i++ )
            pre = pre->next;
    
        ListNode * cur = pre->next;
        ListNode * next;
        for ( int j = left; j < right; j++ )
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }

        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};

class Solution {
public:
    ListNode * mergeTwoList( ListNode * l1, ListNode * l2 )
    {
        //处理双空情况
        if ( l1 == nullptr && l2 == nullptr )
            return nullptr;

        //处理单空情况
        if ( l1 == nullptr || l2 == nullptr )
            return l1 ? l1 : l2;

        //创建虚拟节点，让连接逻辑更流畅
        ListNode * dummy = new ListNode(0);
        ListNode * tail = dummy;

        while ( l1 != nullptr && l2 != nullptr )
        {
            if ( l1->val <= l2->val )
            {
                tail->next = l1;    //直接连接节点，节约内存
                tail = tail->next;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
            
        }
        //连接剩余节点
        tail->next = l1 ? l1 : l2;

        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};

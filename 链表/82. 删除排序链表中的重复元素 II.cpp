class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //凡是可能删除头节点的都要创建哑节点
        ListNode * dummy = new ListNode(0,head);
        ListNode * cur = dummy;
        while ( cur->next && cur->next->next )
        {
            //有两个重复就有可能有多个重复，开始循环删除
            if ( cur->next->val == cur->next->next->val )
            {
                int x = cur->next->val;
                while ( cur->next && cur->next->val == x )
                    cur->next =cur->next->next;
            }
            //如果没有重复就继续遍历
            else 
                cur = cur->next;
        }
        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};

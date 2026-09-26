class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //由于后续一直在给l->next赋值，所以先创建头节点之前的节点
        ListNode * l = new ListNode (0,nullptr);
        ListNode * ans = l;
        while ( list1 != nullptr && list2 != nullptr )
        {
            if ( list1->val >= list2->val )
            {
                l->next = list2;  //注意不能直接给l赋值，否则l->next说不清
                list2 = list2->next;
            }
            else 
            {
                l->next = list1;
                list1 = list1->next;
            }
            l = l->next;
        }
        if ( list1 == nullptr )
            l->next = list2;
        else 
            l->next = list1;

        return ans->next;
    }
};

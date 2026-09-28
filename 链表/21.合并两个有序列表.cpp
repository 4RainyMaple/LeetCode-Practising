//这是一种很自然的解法

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //先处理双空的情况
        if ( list1 == nullptr && list2 == nullptr )
            return nullptr;

        //建立一个新的链表
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        while ( list1 != nullptr && list2 != nullptr )
        {
            int ele;
            if ( list1->val >= list2->val )
            {
                ele = list2->val;
                list2 = list2->next;
            }
            else 
            {
                ele = list1->val;
                list1 = list1->next;
            }
            //处理初次进入循环的情况
            if ( head == nullptr )
                head = tail = new ListNode(ele);
            else 
            {
                tail->next = new ListNode(ele);
                tail = tail->next;
            }
        }

        //如果头指针还是空，说明有一个链表是空，返回非空链表即可
        if ( head == nullptr )
            return list1 ? list1 : list2;

        //处理正常情况，即两个链表都非空
        if ( list1 == nullptr )
            tail->next = list2;
        else 
            tail->next = list1;
        return head;
    }
};

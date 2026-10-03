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
            if ( list1->val >= list2->val )
            {
            //处理初次进入循环的情况
                if ( head == nullptr )
                    head = tail = list2;    //注意不要新建节点，小题无所谓，大一点的内存直接爆了
                else 
                {
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            }
            else 
            {
                if ( head == nullptr )
                    head = tail = list1;
                else 
                {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;
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

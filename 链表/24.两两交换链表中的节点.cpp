class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0,head);
        ListNode * currNode = dummy;
        //这里选择操作当前指针的后两个节点
        while ( currNode->next != nullptr && currNode->next->next != nullptr )
        {
            ListNode * node1 = currNode->next;
            ListNode * node2 = node1->next;
            currNode->next = node2;    //注意当前指针也需要修改！！！
            node1->next = node2->next;
            node2->next = node1;
            currNode = node1;
        }
        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};

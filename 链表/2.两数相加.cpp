class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //先创建头结点和尾节点的指针
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        int carry = 0;  //进位
        //只要这两个表只要有一个不空就继续走
        while ( l1 != nullptr || l2 != nullptr )
        {
            int n1 = 0;
            int n2 = 0;
            if ( l1 != nullptr )
                n1 = l1->val;
            if ( l2 != nullptr )
                n2 = l2->val;
            int sum = n1 + n2 + carry;
            
            //首次进入循环需要需要给首尾指针开辟内存
            if ( head == nullptr )
                head = tail = new ListNode( sum % 10 );
            //先开辟新的尾节点再移动尾指针
            else 
            {
                tail->next = new ListNode( sum % 10 );
                tail = tail->next;
            }
            carry = sum / 10;
            if ( l1 != nullptr )
                l1 = l1->next;
            if ( l2 != nullptr )
                l2 = l2->next;
            
        }
        //循环结束后再追加一次判断
        if ( carry > 0 )
            tail->next = new ListNode(carry);
        return head;
    }
};

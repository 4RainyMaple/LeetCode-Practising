/*核心思想：如果快指针追上慢指针，说明被套圈了
快指针不可能跳过慢指针的，想象成相对运动
只调用两个指针，空间复杂度为O(1)*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head == nullptr || head->next == nullptr )
            return false;

        ListNode * slow = head;
        ListNode * fast = head->next;
        while ( slow != fast )
        {
            if ( fast == nullptr ||fast->next == nullptr )
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

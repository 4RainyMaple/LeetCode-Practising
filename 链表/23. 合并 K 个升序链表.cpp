class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        if ( lists.empty() )
            return nullptr;

        while ( lists.size() > 1 )
        {
            int write = 0;
            for ( int i = 0; i < (int)lists.size(); i += 2)
            {
                if ( i + 1 < lists.size() )
                    lists[write] = mergeTwoList( lists[i], lists[i+1] );
                else    //最后只剩一条就不需要合并了
                    lists[write] = lists[i];

                write++;    //显然write永远不超过i
            }
            lists.resize(write);    //write后面的直接去掉
        }

        return lists[0];
    }

    ListNode * mergeTwoList( ListNode * l1, ListNode * l2 )
    {
        if ( l1 == nullptr && l2 == nullptr )
            return nullptr;

        if ( l1 == nullptr || l2 == nullptr )
            return l1 ? l1 : l2;

        ListNode * dummy = new ListNode(0);
        ListNode * tail = dummy;

        while ( l1 != nullptr && l2 != nullptr )
        {
            if ( l1->val <= l2->val )
            {
                tail->next = l1;
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
            
        tail->next = l1 ? l1 : l2;

        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};

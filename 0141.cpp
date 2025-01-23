/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
        {
            return 0;
        }
        ListNode *slow, *fast;
        slow = new ListNode;
        fast = new ListNode;
        slow = head;
        fast = head;
        while(1)
        {
            if(fast->next == nullptr)
            {
                return 0;
            }
            else if(fast->next->next == nullptr)
            {
                return 0;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return 1;
            }

        }
        
    }
};
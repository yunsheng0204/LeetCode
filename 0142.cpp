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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode *slow, *slow2, *fast;
        slow = new ListNode;
        slow2 = new ListNode;
        fast = new ListNode;
        slow = head;
        slow2 = head;
        fast = head;
        while(1)
        {
            if(fast->next == nullptr)
            {
                return nullptr;
            }
            else if(fast->next->next == nullptr)
            {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                while(slow != slow2)
                {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }

        }
    }
};
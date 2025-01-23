/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *now, *nex, *previous;
        previous = new ListNode;
        now = new ListNode;
        nex = new ListNode;
        previous = nullptr;

        now = head;
        if(now != nullptr)
        {
            nex = now->next;
        }

        while(now != nullptr)
        {
            now->next = previous;
            previous = now;
            now = nex;
            if(now != nullptr)
            {
                nex = nex->next;
            }
        }

        return previous;
    }
};
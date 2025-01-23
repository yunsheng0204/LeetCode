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
    ListNode* swapPairs(ListNode* head) {
        ListNode* n1, *n2, *n3, *n4;
        n1 = new ListNode;
        n2 = new ListNode;
        n3 = new ListNode;
        n4 = new ListNode;

        n2 = head;
        if(head != nullptr)
        {
            n3 = n2->next;
            n1->next = n2;
        }
        else
        {
            return head;
        }
        if(n3 != nullptr)
        {
            head = n3;
            n4 = n3->next;
        }
        else
        {
            return head;
        }

        while(1)
        {
            n1->next = n3;
            n3->next = n2;
            n2->next = n4;

            n1 = n2;
            n2 = n1->next;
            if( n1->next == nullptr )
            {
                return head;
            }
            else if( n2->next == nullptr )
            {
                return head;
            }
            n3 = n2->next;
            n4 = n3->next;
        }
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans;
        ans = new ListNode;
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ans = addTwoNumbers1(l1, l2);

        ans = reverseList(ans);
        return ans;
    }
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
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {

        ListNode* head, *now;
        head = new ListNode;
        now = new ListNode;
        int c = 0;
        int sum = 0;

        now = head;

        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 == nullptr)
            {
                sum = c  + l2->val;
                if(sum>=10)
                {
                    c = 1;
                    sum = sum%10;
                }
                else
                {
                    c = 0;
                }
                now->next =  new ListNode(sum);
                now = now->next;
                l2 = l2->next;
            }
            else if(l2 == nullptr)
            {
                sum = c  + l1->val;
                if(sum>=10)
                {
                    c = 1;
                    sum = sum%10;
                }
                else
                {
                    c = 0;
                }
                now->next =  new ListNode(sum);
                now = now->next;
                l1 = l1->next;
            }
            else
            {
                sum = c + l1->val + l2->val;

                if(sum>=10)
                {
                    c = 1;
                    sum = sum%10;
                }
                else
                {
                    c = 0;
                }
                now->next = new ListNode(sum);
                now = now->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(c == 1)
        {
            now->next = new ListNode(1);
        }
        return head->next;
    }
};


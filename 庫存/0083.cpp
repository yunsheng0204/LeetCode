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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* temp = new ListNode;
        ListNode* pre = new ListNode;

        pre = head;
        temp = head->next;
        while(temp != nullptr)
        {
            if(pre->val == temp->val)
            {
                pre->next = temp->next;
                temp = temp->next;
            }
            else
            {
                pre = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
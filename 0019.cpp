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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> queue;
        ListNode *temp = new ListNode;
        temp = head;
        queue.push_back(temp);
        while(temp->next!=nullptr)
        {
            temp = temp->next;
            queue.push_back(temp);
        }
        int len = queue.size();
        int number = len - n;
        if(n == 1 && len == 1)
        {
            ListNode *ans = new ListNode;
            return nullptr;
        }
        else if(n == 1)
        {
            queue[len-2]->next = nullptr;
        }
        else if(number == 0)
        {
            head = head->next;
        }
        else
        {
            queue[number-1]->next = queue[number+1];
        }
        return head;
    }
};
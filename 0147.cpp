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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ans = new ListNode;
        ListNode *temp = new ListNode;
        vector<ListNode*> queue;
        if(head == nullptr)
        {
            return nullptr;
        }
        temp = head;
        queue.push_back(temp);
        while(temp->next!=nullptr)
        {
            temp = temp->next;
            queue.push_back(temp);
        }
        int len = queue.size();
        
        for(int i = 0; i<len; i++)
        {
            temp = queue[i];
            for(int j = i-1; j>=0; j--)
            {
                if(temp->val < queue[j]->val)
                {
                    queue[j+1] = queue[j];
                    if(j == 0)
                    {
                        queue[j] = temp;
                    }
                }
                else
                {
                    queue[j+1] = temp;
                    break;
                }
            }
        }

        ans = queue[0];
        for(int i = 0; i<len-1; i++)
        {
            queue[i]->next = queue[i+1];
        }
        queue[len-1]->next = nullptr;
        return ans;
    }
};
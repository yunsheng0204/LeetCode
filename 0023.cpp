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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans, *temp;
        ans = new ListNode;
        temp = new ListNode;
        temp = ans;

        int leng = lists.size();
        int pos = 0, min = 10000;
        int i = 0;

        if(leng != 0)
        {
            bool *lock;
            lock = new bool [leng];
            for(i = 0; i < leng; i++)
            {
                lock[i] = 0;
                if(lists[i] == nullptr)
                {
                    lock[i] = 1;
                }
            }
            while(1)
            {
                for(i = 0; i<leng; i++)
                {
                    if(lock[i] == false)
                    {
                        break;
                    }
                    if(i == leng-1)
                    {
                        return ans->next;
                    }
                }
                min = 100000;
                for(i = 0; i<leng; i++)
                {
                    if(lock[i] == 1)
                    {
                        continue;
                    }
                    if(min > lists[i]->val)
                    {
                        min = lists[i]->val;
                        pos = i;
                    }
                }
                temp->next  = new ListNode(min);
                temp = temp->next;
                if(lists[pos]->next == nullptr)
                {
                    lock[pos] = 1;
                }
                else
                {
                    lists[pos] = lists[pos]->next ;
                }
            }
        }
        return ans->next;
    }
};
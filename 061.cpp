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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp;
        temp = new ListNode;
        temp = head;

        int len = 0;

        if(head == nullptr)
        {
            return nullptr;
        }
        else
        {
            while(temp->next != nullptr)
            {
                len++;
                temp = temp->next;
            }
            temp->next = head;
            len++;
            int times = k%len;

            temp = head;

            int cut = len-times-1;

            cout<<cut<<endl;

            for(int i = 0; i<cut; i++)
            {
                temp = temp->next;
            }
            head = temp->next;
            temp->next = nullptr;
        }
        return head;
    }
};
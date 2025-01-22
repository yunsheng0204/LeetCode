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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *previous, *next, *now, *nowpre, *nownex, *h, *r;
        previous = new ListNode;
        next = new ListNode;
        now = new ListNode;
        nowpre = new ListNode;
        nownex = new ListNode;
        h = new ListNode;
        r = new ListNode;

        if(head == nullptr)
        {
            return nullptr;
        }
        else if(k == 1)
        {
            return head;
        }
        else
        {
            r->next = head;
            next = head;
            now = head;
            for(int i = 1;i<k;i++)
            {
                head = head->next;
            }
            while(1)
            {
                previous = h;
                h = next;
                nowpre = r;
                nownex = now->next;
                now = h;
                r = h;
                for(int i = 1; i<=k; i++)
                {
                    if(next->next == nullptr && i!=k)
                    {
                        return head;
                    }
                    else if(next->next == nullptr && i==k)
                    {
                        cout<<"previous "<<previous->val<<endl;
                        cout<<"h "<<h->val<<endl;
                        cout<<"r "<<r->val<<endl;
                        cout<<"next "<<next->val<<endl<<endl;

                        cout<<"nowpre "<<nowpre->val<<endl;
                        cout<<"now "<<now->val<<endl;
                        cout<<"nownex "<<nownex->val<<endl<<endl;
                        for(int i = 1; i<=k; i++)
                        {
                            now->next = nowpre;
                            nowpre = now;
                            now = nownex;
                            if(nownex->next != nullptr)
                            {
                                nownex = nownex->next;
                            }
                        }
                        previous->next = r;
                        h->next = nullptr;
                        return head;
                    }
                    else if(i==k)
                    {
                        next = next->next;
                    }
                    else
                    {
                        r = r->next;
                        next = next->next;
                    }
                }
                cout<<"previous "<<previous->val<<endl;
                cout<<"h "<<h->val<<endl;
                cout<<"r "<<r->val<<endl;
                cout<<"next "<<next->val<<endl<<endl;

                cout<<"nowpre "<<nowpre->val<<endl;
                cout<<"now "<<now->val<<endl;
                cout<<"nownex "<<nownex->val<<endl<<endl;

                for(int i = 1; i<=k; i++)
                {
                    now->next = nowpre;
                    nowpre = now;
                    now = nownex;
                    nownex = nownex->next;
                }
                previous->next = r;
                h->next = next;
                cout<<"newhead "<<r->val<<endl;
                cout<<"newrear "<<h->val<<endl<<endl<<endl<<endl;
            }
        }
        return head;
    }
};
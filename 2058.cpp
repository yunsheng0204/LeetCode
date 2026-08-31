class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* now = new ListNode;
        ListNode* pre = new ListNode;

        vector<int> ans(2, -1);
        int maxi = -1;
        int mini = INT_MAX;
        int index = 0;
        int first_index = 0;
        int pre_index = -1;
        pre = head;
        now = pre->next;

        while(now->next != nullptr)
        {
            index++;
            if(now->val > pre->val && now->val > now->next->val)
            {
                if(pre_index == -1)
                {
                    first_index = index;
                    pre_index = index;
                }
                else
                {
                    maxi = max(maxi, index-first_index);
                    mini = min(mini, index-pre_index);
                    ans = {mini, maxi};
                    pre_index = index;
                }
            }
            else if(now->val < pre->val && now->val < now->next->val)
            {
                cout<<index<<" "<<pre_index<<endl;
                if(pre_index == -1)
                {
                    first_index = index;
                    pre_index = index;
                }
                else
                {
                    maxi = max(maxi, index-first_index);
                    mini = min(mini, index-pre_index);
                    ans = {mini, maxi};
                    pre_index = index;
                }
            }

            pre = now;
            now = now->next;
        }

        return ans;
    }
};